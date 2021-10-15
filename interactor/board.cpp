#include "board.h"

#include <algorithm>
#include <cassert>
#include <numeric>
#include <utility>
#include <iomanip>

Board::Board(ushort stones) {
    std::fill(state.begin(), state.end(), stones);
    state[kalahs[0]] = state[kalahs[1]] = 0;
}

bool Board::IsFinished() const {
    auto is_zero = [](int x) { return x == 0; };
    return std::all_of(state.begin(), state.begin() + kalahs[0], is_zero) ||
           std::all_of(state.begin() + kalahs[0] + 1, state.begin() + kalahs[1], is_zero);
}

int Board::GetScore() const {
    return state[kalahs[0]] - state[kalahs[1]];
}

bool Board::CheckTurnCorrect(std::size_t pos) const {
    return state[pos] != 0 && pos < player_houses;
}

void Board::SwitchPlayers() {
    std::swap_ranges(state.begin(), state.begin() + kalahs[0] + 1, state.begin() + kalahs[0] + 1);
}

std::pair<ushort, ushort> Board::ForceFinish() {
    std::pair<ushort, ushort> free_stones(0, 0);
    free_stones.first = std::accumulate(state.begin(), state.begin() + kalahs[0], ushort(0));
    std::fill(state.begin(), state.begin() + kalahs[0], 0);
    free_stones.second = std::accumulate(state.begin() + kalahs[0] + 1, state.begin() + kalahs[1], ushort(0));
    std::fill(state.begin() + kalahs[0] + 1, state.begin() + kalahs[1], 0);
    return free_stones;
}

bool Board::MakeTurnInplace(std::size_t pos) {
    assert(CheckTurnCorrect(pos));
    ushort stones = state[pos];
    state[pos] = 0;
    while (stones != 0) {
        ++pos;
        if (pos == kalahs[1]) { // Opponent's kalah
            pos = 0;
        }
        ++state[pos];
        --stones;
    }
    if (std::size_t opposite = 2 * kalahs[0] - pos; pos < kalahs[0] && state[pos] == 1 && state[opposite] != 0) {
        state[player_houses] += state[pos] + state[opposite];
        state[pos] = state[opposite] = 0;
    }
    if (IsFinished()) {
        finish = 1;
        auto[v1, v2] = ForceFinish();
        state[kalahs[0]] += v1;
        state[kalahs[1]] += v2;
        return false;
    }
    bool switched = false;
    if (pos != kalahs[0]) {
        SwitchPlayers();
        switched = true;
    }
    return switched;
}

std::pair<Board, bool> Board::MakeTurn(std::size_t pos) const {
    Board b(*this);
    bool switched = b.MakeTurnInplace(pos);
    return {b, switched};
}

std::ostream &operator<<(std::ostream &out, const Board &b) {
    constexpr int num_width = 3;

    out << std::setw(num_width) << ' ';
    for (size_t i = 0; i < Board::player_houses; ++i) {
        out << std::setw(num_width) << b.state[b.kalahs[1] - i - 1];
    }
    out << std::endl;

    out << std::setw(num_width) << b.state[Board::kalahs[1]];
    out << std::setw(num_width * Board::player_houses) << ' ';
    out << std::setw(num_width) << b.state[Board::kalahs[0]];
    out << std::endl;

    out << std::setw(num_width) << ' ';
    for (size_t i = 0; i < Board::player_houses; ++i) {
        out << std::setw(num_width) << b.state[i];
    }
    out << std::endl;

    return out;
}
