#include <iostream>
#include <bits/stdc++.h>
#include <memory>
#include <cmath>

#include "Network.hpp"
#include "Functions.hpp"
#include "Operations.hpp"
#include "Apply.hpp"

using namespace std;
CrossEntropyBack crs_eb0;

int main() {
    double xx = 1, yy = 2;
    auto x = make_shared<variable>(xx);
    auto y = make_shared<variable>(yy);
    std::shared_ptr<NodeTree> v = make_shared<mul>(make_shared<add>(x, y),
    make_shared<expp>(make_shared<poww>(x, make_shared<constant>(2))));
    //std::shared_ptr<NodeTree> v = make_shared<mul>(x, y);
    //Expression v = Mul(Pow(x, y), Constant(2));
    //Expression v = Add(Add(Mul(Pow(x, Constant(2)), Constant(3)), Mul(Constant(2), x)), Constant(4));
    v->Calc();
    auto g = v->val;
    g->grad = 1;
    cout << g->val << endl;
    g->Back();
    cout << x->grad << endl;
    cout << y->grad << endl;
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
