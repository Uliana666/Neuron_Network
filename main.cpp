#include <iostream>
#include <bits/stdc++.h>

#include "Network.h"
#include "Functions.h"

const int IN = 2, OUT = 2;
//using namespace std;

Network net_ret() {
    AbstractActivationFunction *sigm = new Sigmoid();
    AbstractActivationFunction *sfmx = new Softmax();
    AbstractActivationFunction *tgnt = new Tangent();
    AbstractActivationFunction *linr = new Linear_function();
    AbstractActivationFunction *relu = new ReLu();
    AbstractLossFunction *crs_e = new Cross_Entropy();
    AbstractLossFunction *er_sq = new Error_Squared();

    return Network(4, {IN, 4, 4, OUT}, 0.5, {tgnt, tgnt, tgnt, sfmx}, crs_e);
}

int main() {
    auto net = net_ret();
    std::ifstream test("test_circle");
    std::cout << "OK" << std::endl;
    std::vector<double> v(IN), g(OUT);
    for (int i = 0; i < 5000000; ++i) {
        for (int j = 0; j < IN; ++j) test >> v[j];
        for (int j = 0; j < OUT; ++j) test >> g[j];
        net.BackwardProp(v, g);
        if ((i + 1) % 10 == 0) net.Step();
    }
    while (true) {
        std::vector<double> val(IN);
        for (int i = 0; i < IN; ++i) std::cin >> val[i];
        auto vt = net.Calc(val);
        for (auto e: vt) std::cout << e << ' ';
        std::cout << std::endl;
    }
}
