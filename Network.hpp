#ifndef NEURON_NETWORK_NETWORK_HPP
#define NEURON_NETWORK_NETWORK_HPP

#include <random>
#include <memory>
#include "Layer.hpp"
#include <array>
#include "Functions.hpp"
#include <iostream>
#include <random>
#include <utility>
#include <memory>
#include "AutogradOperations.hpp"

using namespace std;
Sigmoid sigm;
Softmax sfmx;
Tangh tgnt;
LinearFunction linr;
ReLu relu;
CrossEntropy crs_e;
ErrorSquared er_sq;

struct Network {
    double speed = 0.08;
    Layer<2, 4> lay1{speed};
    Layer<4, 4> lay2{speed};
    Layer<4, 2> lay3{speed};
    double cnt = 0;

    template<size_t deep>

    std::shared_ptr<Node<Tensor<double, deep, 2>>> ForwardProp(Tensor<double, deep, 2> &data) {
        auto input = CreateAuto(data);
        auto x1 = Func(input, relu);
        auto x2 = Func(lay1.calc(x1), relu);
        auto x3 = Func(lay2.calc(x2), tgnt);
        auto res = SoftMax(lay3.calc(x3));
        return res;
    }

    void Step() {
        lay1.Step(cnt), lay2.Step(cnt), lay3.Step(cnt);
        cnt = 0;
    }

    template<size_t deep>
    void BackwardProp(const Tensor<double, deep, 2> &test, std::shared_ptr<Node<Tensor<double, deep, 2>>> res) {
        auto test_ = CreateAuto(test);
        auto final = Function_loss(res, test_, er_sq);
        std::cout << final->val[0] << ' ';
        final->grad.fill(1);
        final->Back();
    }

    template<class T, size_t deep>
    void Learn(Tensor<T, deep, 2> data, const Tensor<T, deep, 2> &test) {
        BackwardProp(test, ForwardProp(data));
        cnt += deep;
    }

};


#endif