#include <iostream>
#include <bits/stdc++.h>
#include <memory>

#include "Network.h"
#include "Functions.h"
#include "ExpressionTree.h"

const int IN = 2, OUT = 2;
using namespace std;

Network net_ret() {
    shared_ptr<Sigmoid> sigm(new Sigmoid());
    shared_ptr<Softmax> sfmx(new Softmax());
    shared_ptr<Tangh> tgnt(new Tangh());
    shared_ptr<Linear_function> linr(new Linear_function());
    shared_ptr<ReLu> relu(new ReLu());
    shared_ptr<Cross_Entropy> crs_e(new Cross_Entropy());
    shared_ptr<Error_Squared> er_sq(new Error_Squared());
    return Network(4, {IN, 4, 4, OUT}, 0.5, {tgnt, tgnt, tgnt, sfmx}, crs_e);
}

int main() {
    auto net = net_ret();
    std::ifstream test("test_circle");
    std::vector<double> v(IN), g(OUT);
    for (int i = 0; i < 500000; ++i) {
        for (int j = 0; j < IN; ++j) test >> v[j];
        for (int j = 0; j < OUT; ++j) test >> g[j];
        net.BackwardProp(v, g);
        if ((i + 1) % 10 == 0) net.Step();
    }
    std::cout << "GO" << std::endl;
    while (true) {
        std::vector<double> val(IN);
        for (int i = 0; i < IN; ++i) std::cin >> val[i];
        auto vt = net.Calc(val);
        for (auto e: vt) std::cout << e << ' ';
        std::cout << std::endl;
    }
    ExpressionTree a(6);
}
