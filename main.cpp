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
    Network net;
    std::ifstream test("test_circle");
    Tensor<double, 1, 2> v, g;
    for (int i = 0; i < 500000; ++i) {
        test >> v >> g;
        net.Learn(v, g);
        if ((i + 1) % 10 == 0) net.Step();
    }
    std::cout << "GO" << std::endl;
    while (true) {
        Tensor<double, 1, 2> val;
        cin >> val;
        auto vt = net.ForwardProp(val);
        std::cout << vt;
    }
}
