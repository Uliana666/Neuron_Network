#include <iostream>
#include <bits/stdc++.h>
#include <memory>
#include <cmath>

#include "Network.hpp"
#include "Functions.hpp"
#include "GraphCalc.hpp"
#include "Apply.hpp"

using namespace std;
CrossEntropyBack crs_eb0;
#define kek Tensor<double, 2>
#define kek2 Tensor<double>

int main() {
    kek xx(1), yy(2);
    auto x = make_shared<variable<kek>>(xx);
    auto y = make_shared<variable<kek>>(yy);
    auto cnt = make_shared<variable<kek2>>(kek2(2));
    std::shared_ptr<Node<kek>> v = make_shared<mul<kek, kek, kek>>(make_shared<add<kek, kek, kek>>(x, y),
                                                                   make_shared<exp_f<kek>>(
                                                                           make_shared<pow_f<kek, kek, double>>(x, cnt)));
    //std::shared_ptr<Node<kek>> v = make_shared<pow_f<kek, kek, kek>>(x, y);
    //std::shared_ptr<Node<kek>> v = make_shared<add<kek, kek, kek2>>(x, cnt);
    cout << "OK\n";
    v->grad.fill(1);
    cout << v->val << endl;
    v->Back();
    cout << x->grad << endl;
    cout << y->grad << endl;
    cout << cnt->grad << endl;
}
/*int main() {
    const size_t buk = 20;
    Network<buk> net;
    std::ifstream test("test_circle");
    Tensor<double, buk, 2> v, g;
    double kek = 0;
    for (int i = 0; i < 5000000 / buk; ++i) {
        for (int j = 0; j < buk; ++j) test >> v[j] >> g[j];
        net.Learn(v, g, kek);
        std::cout << kek << ' ' << i << std::endl;
        net.Step();
        kek = 0;
    }
    std::cout << "GO" << std::endl;
    while (true) {
        Tensor<double, 1, 2> val;
        cin >> val;
        auto vt = net.Calc(val);
        std::cout << vt;
    }
}*/
