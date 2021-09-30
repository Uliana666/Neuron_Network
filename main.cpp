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
const int N = 3;
//using namespace std;

int main() {
    Network net(4, {N, 4, 4, N}, 0.5, {&tgnt, &tgnt, &tgnt, &sfmx}, &crs_e);
    std::ifstream test("test_3");
    std::vector<double> v(N), g(N);
    for (int i = 0; i < 50000; ++i) {
        for (int j = 0; j < N; ++j) test >> v[j];
        for (int j = 0; j < N; ++j) test >> g[j];
        net.BackwardProp(v, g);
        if ((i + 1) % 10 == 0) net.Step();
    }
    std::cout << "GO" << std::endl;
    while (true) {
        std::vector<double> val(N);
        for (int i = 0; i < N; ++i) std::cin >> val[i];
        auto vt = net.Calc(val);
        for (auto e: vt) std::cout << e << ' ';
        std::cout << std::endl;
    }
}
