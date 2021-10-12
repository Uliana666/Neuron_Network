
#ifndef NEURON_NETWORK_LAYER_HPP
#define NEURON_NETWORK_LAYER_HPP

#include <memory>
#include "Tensor.hpp"
#include "Apply.hpp"
#include "Node.hpp"
#include "AutogradOperations.hpp"

template<size_t in, size_t out>
struct Layer {
    std::shared_ptr<Node<Tensor<double, in, out>>> w = CreateAuto(Tensor<double, in, out>());
    std::shared_ptr<Node<Tensor<double, out>>> b = CreateAuto(Tensor<double, out>());
    double speed;

    Layer(double x) : speed(x) {}

    template<class T, size_t deep>
    std::shared_ptr<Node<Tensor<T, deep, out>>> calc(std::shared_ptr<Node<Tensor<T, deep, in>>> data) {
        auto res = MultyMatrix(data, w);
        return Add_b(res, b);
    }

    void Step(double cnt) {
        w->val -= (w->grad * (speed / cnt));
        b->val -= (b->grad * (speed / cnt));
        b->grad.fill(), w->grad.fill();
    }
};

#endif