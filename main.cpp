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
    Network net;
    std::ifstream test("test_circle");
    Tensor<double, 1, 2> v, g;
    for (int i = 0; i < 5000; ++i) {
        test >> v >> g;
        net.Learn(v, g);
        std::cout << i << std::endl;
        if ((i + 1) % 10 == 0) net.Step();
    }
    std::cout << "GO" << std::endl;
    while (true) {
        Tensor<double, 1, 2> val;
        cin >> val;
        auto vt = net.ForwardProp(val);
        std::cout << vt << std::endl;
    }
}
