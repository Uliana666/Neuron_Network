#include <iostream>
#include <bits/stdc++.h>
#include <memory>

#include "Network.h"
#include "Functions.h"
#include "ExpressionTree.h"
#include "Tensor.hpp"

const int IN = 2, OUT = 2;
using namespace std;

Network net_ret() {
    shared_ptr<Sigmoid> sigm(new Sigmoid());
    shared_ptr<Softmax> sfmx(new Softmax());
    shared_ptr<Tangh> tgnt(new Tangh());
    shared_ptr<LinearFunction> linr(new LinearFunction());
    shared_ptr<ReLu> relu(new ReLu());
    shared_ptr<CrossEntropy> crs_e(new CrossEntropy());
    shared_ptr<ErrorSquared> er_sq(new ErrorSquared());
    return Network(4, {IN, 4, 4, OUT}, 0.5, {tgnt, tgnt, tgnt, sfmx}, crs_e);
}

int main() {
    Tensor<double, 2, 4> t(3);
    Tensor<double, 4, 1> t2(8);
    cin >> t;
    cin >> t2;
    auto kek = t.multy(t2);
    cout << kek;
    return 0;
    auto net = net_ret();
    std::ifstream test("test_circle");
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
    }
}
// f = f1 + f2
// f' = f1' + f2'
// y = y1 + y2
