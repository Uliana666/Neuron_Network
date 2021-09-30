#include <iostream>
#include <bits/stdc++.h>

#include "Network.h"
#include "Functions.h"

Sigmoid sigm;
Softmax sfmx;
Tangent tgnt;
Linear_function linr;
Cross_Entropy crs_e;
Error_Squared er_sq;
const int IN = 3, OUT = 3;
//using namespace std;

int main() {
    Network net(4, {IN, 4, 4, OUT}, 0.5, {&tgnt, &tgnt, &tgnt, &sfmx}, &er_sq);
    std::ifstream test("test_sphere_output3");
    std::vector<double> v(IN), g(OUT);
    for (int i = 0; i < 50000; ++i) {
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
