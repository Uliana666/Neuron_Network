#include <iostream>
#include "board.h"
#include <vector>
#include "random"

const int DEEP = 100, MAXN = 5e6;
std::mt19937 rnd;
Board game(6);

bool GetRandomMove(Board &b) {
    int ct = 0;
    for (int i = 0; i < 6; ++i) if (b.CheckTurnCorrect(i)) ct++;
    ct = rnd() % ct + 1;
    for (int i = 0; i < 6; ++i)
        if (b.CheckTurnCorrect(i)) {
            --ct;
            if (!ct) return b.MakeTurnInplace(i);
        }
}

double PlayRandomGame(Board b) {
    int switched = 0;
    while (!b.finish) switched ^= GetRandomMove(b);
    if (switched) return -b.GetScore();
    return b.GetScore();
}

struct vertex {
    std::vector<vertex*> child{6, nullptr};
    Board board;
    double n, result;
    bool type, check;

    void GenChild() {
        if (board.IsFinished()) return;
        for (int i = 0; i < 6; ++i) {
            if (board.CheckTurnCorrect(i)) {
                child[i] = new vertex(this, i);
            }
        }
    }

    vertex(vertex *parent, int a) : board(parent->board.MakeTurn(a).first),
                                    type(parent->board.MakeTurn(a).second ^ parent->type), n(0),
                                    result(0), check(0) {
        if (board.IsFinished()) ++n, result = board.GetScore();
    }

    vertex *GetBestChild() {
        double max_res = 1e200 * -1.;
        vertex *pos = nullptr;
        int smN = 0;
        for (const auto &u: child) if (u) smN += u->n;
        for (const auto &u: child) {
            if (!u) continue;
            double d = double(u->result) / (u->n + 1);
            if (u->type != type) d = -d;
            d += 20. * sqrt(smN) / (1. + u->n);
            if (max_res < d) {
                max_res = d;
                pos = u;
            }
        }
        return pos;
    }

    int GetMove() {
        double max_res = 1e200 * -1;
        int pos = -1;
        for (int i = 0; i < 6; ++i) {
            auto u = child[i];
            if (!u) continue;
            double d = (double) u->result / (u->n + 1);
            if (u->type != type) d = -d;
            if (max_res < d) {
                max_res = d;
                pos = i;
            }
        }
        return pos;
    }

    void GetModel() {
        if (check) return;
        auto tim = clock();
        for (int i = 0; i < DEEP; ++i) result += PlayRandomGame(board);
        //std::cout << "TIME " << 1000. * (clock() - tim) / CLOCKS_PER_SEC << std::endl;
        result /= DEEP, ++n;
        check = 1;
        GenChild();
    }

    int GetType() const {
        if (type) return -1;
        return 1;
    }

    vertex() : board(game), n(0), result(0), type(0), check(0) {
        GetModel();
    }
};

int search(vertex *v) {
    if (v->board.IsFinished()) return v->result * v->GetType();
    if (!v->check) {
        v->GetModel();
        return v->result * v->GetType();
    }
    auto a = v->GetBestChild();
    auto w = search(a);
    v->result += w * v->GetType(), ++v->n;
    return w;
}

vertex *cur_v = new vertex();

bool MyMove() {
    if (game.IsFinished()) return 1;
    auto tim = clock();
    int ct = 0;
    while (1000. * (clock() - tim) / CLOCKS_PER_SEC < 2500.) {
        ct++;
        search(cur_v);
    }
    std::cerr << "!" << ct << std::endl;
    auto pos = cur_v->GetMove();
    cur_v = cur_v->child[pos];
    if (cur_v->check == 0) cur_v->GetModel();
    std::cout << pos + 1 << std::endl;
    auto kek = game.MakeTurnInplace(pos);
    return kek;
}

bool YouMove() {
    if (game.IsFinished()) return 1;
    int pos;
    std::cerr << game << std::endl;
    std::cin >> pos;
    --pos;
    cur_v = cur_v->child[pos];
    if (cur_v->check == 0) cur_v->GetModel();
    return game.MakeTurnInplace(pos);
}

int main() {
    int kek, we;
    std::cin >> kek >> we;
    if (we == 2) we = 0;
    while (!game.IsFinished()) {
        if (we) while (!MyMove());
        else while (!YouMove());
        we ^= 1;
    }
}