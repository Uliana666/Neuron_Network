
#ifndef NEURON_NETWORK_LAYER_HPP
#define NEURON_NETWORK_LAYER_HPP

#include "Tensor.hpp"
#include "Apply.hpp"

template<size_t in, size_t out>
struct Layer {
    Tensor<double, in, out> w, w_gradient{0};
    Tensor<double, out> b, b_gradient{0};
    int cnt = 0;
    double speed;

    Layer(double x) : speed(x) {}

    template<class T, size_t deep>
    Tensor<T, deep, out> calc(const Tensor<T, deep, in> &data) {
        auto res = multy(data, w);
        for (auto &e: res.data) e += b;
        return res;
    }

    template<class T, size_t deep>
    Tensor<T, deep, in> calcb(const Tensor<T, deep, out> &data) {
        return multy(data, Transposition(w));
    }

    template<class T, size_t deep>
    void MoveGradient(const Tensor<T, deep, out> &lay, const Tensor<T, deep, in> &output) {
        ++cnt;
        w_gradient += multy(Transposition(output), lay);
        for (auto &e: lay.data) b_gradient += e;
    }

    void Step() {
        if (!cnt) return;
        w -= (w_gradient *= speed / cnt);
        b -= (b_gradient *= speed / cnt);
        b_gradient.fill(), w_gradient.fill();
        cnt = 0;
    }
};

#endif