
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
    Tensor<T, 1, out> calc(const Tensor<T, 1, in> &data) {
        auto res = multy(data, w);
        res += b;
        return res;
    }

    template<class T>
    Tensor<T, 1, in> calcb(const Tensor<T, 1, out> &data) {
        return multy2(data, w);
    }

    template<class T>
    void MoveGradient(const Tensor<T, 1, out> &lay, const Tensor<T, 1, in> &output) {
        ++cnt;
        w_gradient += multy1(output, lay);
        b_gradient += lay;
    }

    void Step() {
        if (!cnt) return;
        w -= (w_gradient *= speed / cnt);
        b -= (b_gradient *= speed / cnt);
        b_gradient.fill();
        w_gradient.fill();
        cnt = 0;
    }
};

#endif