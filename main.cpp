#include <iostream>
#include <bits/stdc++.h>
#include <memory>
#include <cmath>

#include "Network.hpp"
#include "Functions.hpp"
#include "ExpressionTree.h"
#include "Apply.hpp"

using namespace std;

int main() {
    const size_t buk = 64;
    Network<buk> net;
    std::ifstream test("test_circle");
    Tensor<double, buk, 2> v, g;
    for (int i = 0; i < 50000; ++i) {
        for (int j = 0; j < buk; ++j) test >> v[j] >> g[j];
        net.Learn(v, g);
        net.Step();
    }
    std::cout << "GO" << std::endl;
    while (true) {
        Tensor<double, 1, 2> val;
        cin >> val;
        auto vt = net.Calc(val);
        std::cout << vt;
    }
}
