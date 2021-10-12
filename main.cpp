#include <iostream>
#include <bits/stdc++.h>
#include <memory>
#include <cmath>

#include "Network.hpp"
#include "Functions.hpp"
#include "GraphCalc.hpp"
#include "Apply.hpp"
#include "AutogradOperations.hpp"

using namespace std;
CrossEntropyBack crs_eb0;

int main() {
    auto x = CreateAuto(Tensor<double, 2, 3>(2));
    auto y = CreateAuto(Tensor<double, 2, 3>(3));
    auto xy = (x * y);

    //shared_ptr<Node<kek>> v = make_shared<mul<kek, kek, kek>>(make_shared<add<kek, kek, kek>>(x, y),
    //make_shared<exp_f<kek>>(
    //make_shared<pow_f<kek, kek, double>>(x, cnt)));
    //shared_ptr<Node<kek>> v = make_shared<pow_f<kek, kek, kek>>(x, y);
    //shared_ptr<Node<kek>> v = make_shared<add<kek, kek, kek2>>(x, cnt);
    ///
    /*Tensor<double, 3, 2> xx(1);
    Tensor<double, 2, 5> yy(2);
    auto x = make_shared<variable<Tensor<double, 3, 2>>>(xx);
    auto y = make_shared<variable<Tensor<double, 2, 5>>>(yy);
    shared_ptr<Node<Tensor<double, 3, 5>>> v = make_shared<multy_matrix<double, 3, 2, 5>>(x, y);
    v->grad.fill(1);
    v->Back();
    cout << v->val << endl;
    cout << x->grad << endl;
    cout << y->grad << endl;*/
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
