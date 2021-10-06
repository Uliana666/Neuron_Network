
#ifndef NEURON_NETWORK_LAYER_H
#define NEURON_NETWORK_LAYER_H

#include "Tensor.hpp"
#include "Apply.hpp"

template<size_t in, size_t out>
struct Layer {
    Tensor<double, in, out> w;
    Tensor<double, 1, out> b;

    template<class T>
    Tensor<T, 1, out> calc(Tensor<T, 1, in> data) {
        Tensor<T, 1, out> res = b;
        res += data.multy(w);
        return res;
    }
};

#endif