#include <iostream>
#include <bits/stdc++.h>
#include <memory>
#include <cmath>

#include "Network.hpp"
#include "Functions.hpp"
#include "Expression.hpp"
#include "Operations.hpp"
#include "Apply.hpp"

using namespace std;
CrossEntropyBack crs_eb0;

int main() {
    auto x = Variable("x");
    auto y = Variable("y");
    Expression v = Mul(Add(x, y), Exp(Pow(x, Constant(2))));
    //Expression v = Mul(Pow(x, y), Constant(2));
    //Expression v = Add(Add(Mul(Pow(x, Constant(2)), Constant(3)), Mul(Constant(2), x)), Constant(4));
    auto g = v.Evaluate({{"x", 1},
                         {"y", 2}});
    cout << g->val << endl;
    g->Back(1);
    cout << x.root->grad << endl;
    cout << y.root->grad << endl;
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
