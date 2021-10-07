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
        for (auto e: res.data) sm += exp(e);
        for (auto &e: res.data) e = exp(e) / sm;
        return res;
    }
};


struct CrossEntropy {
    template<CTensor T>
    double operator()(T &out, T &test) {
        if constexpr(T::dim == 0) return -test.data * log(out.data);
        else {
            double res = 0;
            for (size_t i = 0; i < T::n; ++i)
                res += (*this)(out[i], test[i]);
            return res;
        }
    }
};

struct ErrorSquared {
    template<CTensor T>
    double operator()(T &out, T &test) {
        if constexpr(T::dim == 0) return (out.data - test.data) * (out.data - test.data);
        else {
            double res = 0;
            for (size_t i = 0; i < T::n; ++i)
                res += (*this)(out[i], test[i]);
            return res / T::n;
        }
    }
};

//Back_function
struct SigmoidBack {

    double operator()(double x) {
        Sigmoid calc;
        return 2. * calc(x) * (1. - calc(x));
    }

};

struct TanghBack {

    double operator()(double x) {
        return (exp(x) - exp(-x)) / (exp(x) + exp(-x));
    }
};

struct LinearFunctionBack {
    double operator()(double x) {
        return x;
    }
};

struct ReLuBack {
    double operator()(double x) {
        return x < 0 ? 0.01 : 1.;
    }
};

struct SoftmaxBack {
    template<size_t len>
    Tensor<double, len> operator()(Tensor<double, len> dE, Tensor<double, len> x) {
        Tensor<double, len> res(0);
        double sm = 0;
        for (auto &e: x.data) sm += exp(e);
        for (size_t i = 0; i < len; ++i) {
            for (size_t k = 0; k < len; ++k) {
                if (i != k)
                    res[i] += -dE[k] * exp(x[k]) * exp(x[i]) / sm / sm;
                else
                    res[i] += dE[k] * exp(x[k]) * (sm - exp(x[k])) / sm / sm;
            }
        }
        return res;
    }
};


struct CrossEntropyBack {
    template<CTensor T>
    void operator()(T &out, T &test) {
        if constexpr(T::dim == 0) out = -test.data / out.data;
        else
            for (size_t i = 0; i < T::n; ++i)
                (*this)(test[i], out[i]);
    }
};

struct ErrorSquaredBack {
    template<CTensor T>
    void operator()(T &out, T &test) {
        if constexpr(T::dim == 0) out = 2. * (out.data - test.data);
        else {
            for (size_t i = 0; i < T::n; ++i)
                (*this)(out[i], test[i]);
            out /= T::n;
        }
    }
};

#endif
