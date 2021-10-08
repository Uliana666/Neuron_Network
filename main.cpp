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
    Expression v = Mul(Add(Variable("x"), Variable("y")), Exp(Pow(Variable("x"), Constant(2))));
    auto g = v.Evaluate({{"x", 1},
                         {"y", 2}});
    cout << g->val;
    //cout << u.Evaluate({{"x", 6}});
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
