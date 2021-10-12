#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

#include "Network.hpp"

using namespace std;

int main() {
    const size_t buk = 20;
    Network net;
    std::ifstream test("test_circle");
    Tensor<double, buk, 2> v, g;
    for (int i = 0; i < 500000 / buk; ++i) {
        for (int j = 0; j < buk; ++j) test >> v[j] >> g[j];
        net.Learn(v, g);
        std::cout << i << std::endl;
        if ((i + 1) % 1 == 0) net.Step();
    }
    std::cout << "GO" << std::endl;
    while (true) {
        Tensor<double, 1, 2> val;
        cin >> val;
        auto vt = net.ForwardProp(val);
        std::cout << vt->val;
    }
}
