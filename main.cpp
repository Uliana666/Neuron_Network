#include <iostream>
#include "bits/stdc++.h"

#include "Network.h"

int main() {
    Network net;
    //std::ifstream test("test_3");
    std::ifstream test("test_multi3");
    //std::ifstream test("test_multi");
    std::vector<double> v(N), g(N);
    for (int i = 0; i < 50000; ++i) {
        for (int j = 0; j < N; ++j) test >> v[j];
        for (int j = 0; j < N; ++j) test >> g[j];
        net.Learn(v, g);
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
