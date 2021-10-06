#ifndef NEURON_NETWORK_FUNCTIONS_H
#define NEURON_NETWORK_FUNCTIONS_H

#include <iostream>
#include <vector>
#include <memory>
#include "Tensor.hpp"

struct Sigmoid {

    double operator()(double x) {
        return 1. / (1. + exp(-2. * x));
    }

};

struct Tangh {

    double operator()(double x) {
        return (exp(x) - exp(-x)) / (exp(x) + exp(-x));
    }
};

struct LinearFunction {
    double operator()(double x) {
        return x;
    }
};

struct ReLu {
    double operator()(double x) {
        return x < 0 ? 0.01 * x : x;
    }
};

struct Softmax {
    template<size_t len>
    Tensor<double, len> operator()(Tensor<double, len> x) {
        auto res = x;
        double sm = 0;
        for (auto e: res) sm += exp(e);
        for (auto& e: res) e = exp(e) / sm;
        return res;
    }
};


struct CrossEntropy {
    template<class T, size_t len>
    double operator()(Tensor<T, len> out, Tensor<T, len> test){
        double res = 0;
        for (size_t i = 0; i < len; ++i)
            res -= test[i] * log(out[i]);
        return res;
    }
};

struct ErrorSquared {
    template<class T, size_t len>
    double operator()(Tensor<T, len> out, Tensor<T, len> test){
        double res = 0;
        for (size_t i = 0; i < len; ++i)
            res += (out[i] - test[i]) * (out[i] - test[i]);
        return res / len;
    }
};

#endif
