#include "Functions.h"
#include "cmath"

double Sigmoid::calc(const double &x) {
    return 1. / (1. + exp(-2. * x));
}

std::vector<double> Sigmoid::forward_prop(const std::vector<double> &input) {
    std::vector<double> res(input.size());
    for (size_t i = 0; i < res.size(); ++i)
        res[i] = calc(input[i]);
    return res;
}

std::vector<double> Sigmoid::backward_prop(const std::vector<double> &input, const std::vector<double> &dE) {
    std::vector<double> res = dE;
    for (size_t i = 0; i < input.size(); ++i)
        res[i] *= 2. * calc(input[i]) * (1. - calc(input[i]));
    return res;
}

std::vector<double> Softmax::forward_prop(const std::vector<double> &input) {
    std::vector<double> res(input.size());
    double sm = 0;
    for (auto &e: input)
        sm += exp(e);
    for (size_t i = 0; i < res.size(); ++i)
        res[i] = exp(input[i]) / sm;
    return res;
}

std::vector<double> Softmax::backward_prop(const std::vector<double> &input, const std::vector<double> &dE) {
    std::vector<double> res(dE.size(), 0);
    double sm = 0;
    for (auto e: input) sm += exp(e);
    for (size_t i = 0; i < dE.size(); ++i) {
        for (size_t k = 0; k < dE.size(); ++k) {
            if (i != k)
                res[i] += -dE[k] * exp(input[k]) * exp(input[i]) / sm / sm;
            else
                res[i] += dE[k] * exp(input[k]) * (sm - exp(input[k])) / sm / sm;
        }
    }
    return res;
}