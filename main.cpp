#include <iostream>
#include <bits/stdc++.h>
#include <memory>
#include <cmath>

#include "Network.hpp"
#include "Functions.hpp"
#include "ExpressionTree.h"
#include "Apply.hpp"

const size_t IN = 2, OUT = 2;
using namespace std;

int main() {
    //Network net;
    Tensor<double, 5> kek(4);
    ActivateInline<0>(kek, sigm);
    cout << kek;
    return 0;
    /*std::ifstream test("test_circle");
    std::vector<double> v(IN), g(OUT);
    for (int i = 0; i < 500000; ++i) {
        for (int j = 0; j < IN; ++j) test >> v[j];
        for (int j = 0; j < OUT; ++j) test >> g[j];
        net.Learn(v, g);
        if ((i + 1) % 10 == 0) net.Step();
    }
    std::cout << "GO" << std::endl;
    while (true) {
        std::vector<double> val(IN);
        for (int i = 0; i < IN; ++i) std::cin >> val[i];
        auto vt = net.ForwardProp(val);
        for (auto e: vt) std::cout << e << ' ';
        std::cout << std::endl;
    }*/
}
