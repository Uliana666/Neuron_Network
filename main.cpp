#include <iostream>
#include <bits/stdc++.h>
#include <memory>
#include <cmath>

#include "Network.hpp"
#include "Functions.hpp"
#include "ExpressionTree.h"
#include "Apply.hpp"

using namespace std;
CrossEntropyBack crs_eb0;

int main() {
    const size_t buk = 1;
    Network<buk> net;
    std::ifstream test("test_circle");
    Tensor<double, buk, 2> v, g;
    double kek = 0;
    for (int i = 0; i < 1000000 / buk; ++i) {
        for (int j = 0; j < buk; ++j) test >> v[j] >> g[j];
        //std::cout << v << '\n' << g;
        net.Learn(v, g, kek);
        if ((i + 1) % 20 == 0) {
            std::cout << kek << std::endl;
            kek = 0;
            net.Step();
        }
    }
    std::cout << "GO" << std::endl;
    while (true) {
        Tensor<double, 1, 2> val;
        cin >> val;
        auto vt = net.Calc(val);
        std::cout << vt;
    }
}
