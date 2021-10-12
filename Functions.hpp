#ifndef NEURON_NETWORK_FUNCTIONS_HPP
#define NEURON_NETWORK_FUNCTIONS_HPP

#include <iostream>
#include <vector>
#include <memory>
#include "Tensor.hpp"

struct Sigmoid {

    static double Forward(double x) {
        return 1. / (1. + exp(-2. * x));
    }

    static double Backward(double x) {
        return 2. * Forward(x) * (1. - Forward(x));
    }

};

struct Tangh {

    static double Forward(double x) {
        return (exp(x) - exp(-x)) / (exp(x) + exp(-x));
    }

    static double Backward(double x) {
        Tangh calc;
        return 1. - Forward(x) * Forward(x);
    }
};

struct LinearFunction {
    static double Forward(double x) {
        return x;
    }

    static double Backward(double x) {
        return x;
    }
};

struct ReLu {
    static double Forward(double x) {
        return x < 0 ? 0.01 * x : x;
    }

    static double Backward(double x) {
        return x < 0 ? 0.01 : 1.;
    }
};

struct Softmax {
    template<size_t len>
    Tensor<double, len> operator()(const Tensor<double, len> &x) {
        auto res = x;
        double sm = 0;
        for (auto e: res.data) sm += exp(e);
        for (auto &e: res.data) e = exp(e) / sm;
        return res;
    }
};


struct CrossEntropy {
    template<CTensor T>
    double Forward(const T &out, const T &test) {
        if constexpr(T::dim == 0) return -test.data * log(out.data);
        else {
            double res = 0;
            for (size_t i = 0; i < T::n; ++i)
                res += (*this)(out[i], test[i]);
            return res;
        }
    }

    template<CTensor T>
    void Backward(T &out, const T &test, T &res) {
        if constexpr(T::dim == 0) {
            if (test.data > 0.) res = -test.data / out.data;
            else res = 0;
        } else
            for (size_t i = 0; i < T::n; ++i)
                Backward(out[i], test[i], res[i]);
    }

};

struct ErrorSquared {
    template<CTensor T>
    double Forward(const T &out, const T &test) {
        if constexpr(T::dim == 0) return (out.data - test.data) * (out.data - test.data);
        else {
            double res = 0;
            for (size_t i = 0; i < T::n; ++i)
                res += Forward(out[i], test[i]);
            return res / T::n;
        }
    }

    template<CTensor T>
    void Backward(T &out, const T &test, T &res) {
        if constexpr(T::dim == 0) res = 2. * (out.data - test.data);
        else {
            for (size_t i = 0; i < T::n; ++i)
                Backward(out[i], test[i], res[i]);
            res /= T::n;
        }
    }
};

//Back_function

struct SoftmaxBack {
    template<CTensor T>
    void operator()(const T &dE, const T &x, T &res) {
        if constexpr(T::dim == 1) {
            double sm = 0;
            for (auto &e: x.data) sm += exp(e);
            for (size_t i = 0; i < T::n; ++i) {
                for (size_t k = 0; k < T::n; ++k) {
                    if (i != k)
                        res[i] += -dE[k] * exp(x[k]) * exp(x[i]) / sm / sm;
                    else
                        res[i] += dE[k] * exp(x[k]) * (sm - exp(x[k])) / sm / sm;
                }
            }
        } else {
            for (size_t i = 0; i < T::n; ++i) (*this)(dE[i], x[i], res[i]);
        }
    }
};


#endif
