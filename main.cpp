#include <iostream>
#include <bits/stdc++.h>
#include <memory>

#include "Network.h"
#include "Functions.h"

const int IN = 2, OUT = 2;

Network net_ret() {
    Sigmoid sigm;
    Softmax sfmx;
    Tangent tgnt;
    Linear_function linr;
    ReLu relu;
    Cross_Entropy crs_e;
    Error_Squared er_sq;
    return Network(4, {IN, 4, 4, OUT}, 0.5,
                   {tgnt.GetSharedPtr(), tgnt.GetSharedPtr(), tgnt.GetSharedPtr(), sfmx.GetSharedPtr()},
                   crs_e.GetSharedPtr());
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
}
