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

void print(Network &n) {
    cout << "-----------------------------------------------\n";
    cout << "-------w\n";
    cout << "lay1: \n";
    cout << n.lay1.w << endl;
    cout << "lay2: \n";
    cout << n.lay2.w << endl;
    cout << "lay3: \n";
    cout << n.lay3.w << endl;
    cout << "-------b: \n";
    cout << "lay1: \n";
    cout << n.lay1.b << endl;
    cout << endl;
    cout << "lay2: \n";
    cout << n.lay2.b << endl;
    cout << endl;
    cout << "lay3: \n";
    cout << n.lay3.b << endl;
    cout << endl;
}

int main() {
    Network net;
    cin >> net.lay1.w;
    cin >> net.lay2.w;
    cin >> net.lay3.w;
    cin >> net.lay1.b;
    cin >> net.lay2.b;
    cin >> net.lay3.b;
    std::ifstream test("test_circle");
    Tensor<double, 1, 2> v, g;
    for (int i = 0; i < 10; ++i) {
        print(net);
        test >> v >> g;
        net.Learn(v, g);
        std::cout << i << std::endl;
        if ((i + 1) % 10 == 0) net.Step();
    }
    print(net);
    std::cout << "GO" << std::endl;
    while (true) {
        Tensor<double, 1, 2> val;
        cin >> val;
        auto vt = net.ForwardProp(val);
        std::cout << vt << std::endl;
    }
}
