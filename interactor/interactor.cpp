#include "../board.h"

#include <fstream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#include <tuple>
#include <array>

constexpr ushort initial_stones = 6;

std::tuple<pid_t, FILE*, FILE*> RunStrategy(const std::string& exec, const std::string& err) {
    int sin[2], sout[2];
    pipe2(sin, O_CLOEXEC);
    pipe2(sout, O_CLOEXEC);

    pid_t pid = fork();
    if (!pid) {
        int errfd = open(err.c_str(), O_WRONLY | O_CREAT | O_APPEND | O_CLOEXEC , 0666);
        dup2(sin[0], STDIN_FILENO);
        dup2(sout[1], STDOUT_FILENO);
        dup2(errfd, STDERR_FILENO);
        execl(exec.c_str(), exec.c_str(), nullptr);
        std::cerr << "Exec failed: " << strerror(errno) << std::endl;
        _exit(127);
    }
    close(sin[0]);
    close(sout[1]);
    FILE* in = fdopen(sin[1], "w");
    FILE* out = fdopen(sout[0], "r");
    return {pid, in, out};
}

int RunGame(const std::array<std::string, 2>& execs, const std::array<std::string, 2>& errs, std::ofstream& game_log) {
    game_log << execs[0] << " vs " << execs[1] << std::endl;
    Board board(initial_stones);
    pid_t pids[2];
    FILE* in[2];
    FILE* out[2];
    for (int i = 0; i < 2; ++i) {
        std::tie(pids[i], in[i], out[i]) = RunStrategy(execs[i], errs[i]);
        fprintf(in[i], "%hu\n%d\n", initial_stones, i + 1);
        fflush(in[i]);
    }
    int current_player = 0;
    while (!board.IsFinished()) {
        ushort turn;
        bool force_finish = false;
        if (fscanf(out[current_player], "%hu", &turn) != 1) {
            game_log << "Player " << execs[current_player] << " printed incorrect turn" << std::endl;
            force_finish = true;
        } else {
            game_log << execs[current_player] << ": " << turn << std::endl;
            if (turn < 1 || turn > Board::player_houses) {
                game_log << "Player " << execs[current_player] << " printed incorrect turn" << std::endl;
                force_finish = true;
            } else if (!board.CheckTurnCorrect(--turn)) {
                game_log << "Player " << execs[current_player] << " printed index of empty house" << std::endl;
                force_finish = true;
            }
        }
        if (force_finish) {
            auto [s1, s2] = board.ForceFinish();
            board.state[Board::kalahs[current_player ^ 1]] += s1 + s2;
            break;
        }

        fprintf(in[current_player ^ 1], "%d\n", turn + 1);
        fflush(in[current_player ^ 1]);
        current_player ^= board.MakeTurnInplace(turn);
        if (current_player) {
            board.SwitchPlayers();
        }
        game_log << board << std::endl;
        if (current_player) {
            board.SwitchPlayers();
        }
    }
    for (int i = 0; i < 2; ++i) {
        waitpid(pids[i], nullptr, 0);
    }
    if (current_player) {
        board.SwitchPlayers();
    }
    int k1 = board.state[Board::kalahs[0]], k2 = board.state[Board::kalahs[1]];
    game_log << "Final game score: " << k1 << ":" << k2 << std::endl << std::endl;
    return k1 - k2;
}

int main(int argc, char* argv[]) {
    if (argc != 6) {
        std::cerr << "Usage: " << argv[0] << " executable1 error1 executable2 error2 game_log\n";
        return 0;
    }
    std::array<std::string, 2> execs = {argv[1], argv[3]};
    std::array<std::string, 2> errs = {argv[2], argv[4]};
    for (auto& err: errs) {
        std::ofstream{err};
    }
    std::ofstream game_log(argv[5]);
    int balance = 0, mul = 1;
    for (int i = 0; i < 2; ++i) {
        game_log << "Game #" << i + 1 << std::endl;
        balance += RunGame(execs, errs, game_log) * mul;
        std::swap(execs[0], execs[1]);
        std::swap(errs[0], errs[1]);
        mul = -mul;
    }
    game_log << "Final balance: " << balance << std::endl;
    std::cout << balance << std::endl;
}
