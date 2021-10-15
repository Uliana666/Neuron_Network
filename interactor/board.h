#include <array>
#include <ostream>
#include <utility>

struct Board {
    using ushort = unsigned short;

    Board(ushort stones);

    Board(const Board &) = default;

    bool IsFinished() const;

    int GetScore() const;

    bool CheckTurnCorrect(std::size_t pos) const;

    void SwitchPlayers();

    std::pair<ushort, ushort> ForceFinish();

    bool MakeTurnInplace(std::size_t pos);

    std::pair<Board, bool> MakeTurn(std::size_t pos) const; //  Returns pair {new_state, was_switch}

    static constexpr std::size_t player_houses = 6;
    static constexpr std::size_t total_houses = 2 * player_houses + 2;
    static constexpr std::array<std::size_t, 2> kalahs = {player_houses, 2 * player_houses + 1};
    bool finish = 0;

    std::array<ushort, total_houses> state;
};

std::ostream &operator<<(std::ostream &, const Board &); //  Prints board state in human-readable format
