
#ifndef NEURON_NETWORK_LAYER_H
#define NEURON_NETWORK_LAYER_H

#include "Tensor.hpp"
#include "Apply.hpp"

template<size_t in, size_t out>
struct Layer {
    Tensor<double, in, out> w, w_gradient{0};
    Tensor<double, 1, out> b, b_gradient{0};
    int cnt = 0;
    double speed;

    Layer(double x) : speed(x) {}

    template<class T>
    Tensor<T, 1, out> calc(Tensor<T, 1, in> data) {
        Tensor<T, 1, out> res = b;
        res += data.multy(w);
        return res;
    }

    template<class T>
    Tensor<T, 1, in> calcb(Tensor<T, 1, out> data) {
        Tensor<T, 1, in> res(0);
        for (int j = 0; j < in; ++j)
            for (int k = 0; k < out; ++k)
                res[0][j] += data[0][k] * w[j][k];
        return res;
    }

    template<class T>
    void MoveGradient(Tensor<T, 1, out> &lay, Tensor<T, 1, in> &output) {
        ++cnt;
        for (size_t j = 0; j < in; ++j) {
            for (size_t k = 0; k < out; ++k)
                w_gradient[j][k] += lay[0][k] * output[0][j];
        }
        b_gradient += lay;
    }

    void Step() {
        if (!cnt) return;
        w_gradient *= speed / cnt;
        b_gradient *= speed / cnt;
        w -= w_gradient;
        b -= b_gradient;
        b_gradient.fill();
        w_gradient.fill();
        cnt = 0;
    }
};

#endif