#ifndef NEURON_NETWORK_FUNCTIONS_H
#define NEURON_NETWORK_FUNCTIONS_H

#include "AbstractActivationFunction.h"
#include "AbstractLossFunction.h"
#include <iostream>
#include <vector>
#include <memory>

struct Sigmoid : public AbstractActivationFunction {
    static double calc(const double &x);

    std::vector<double> forward_prop(const std::vector<double> &input) override;

    std::vector<double> backward_prop(const std::vector<double> &input, const std::vector<double> &dE) override;
};

struct Softmax : public AbstractActivationFunction {
    std::vector<double> forward_prop(const std::vector<double> &input) override;

    std::vector<double> backward_prop(const std::vector<double> &input, const std::vector<double> &dE) override;
};

struct Tangh : public AbstractActivationFunction {
    static double calc(const double &x);

    std::vector<double> forward_prop(const std::vector<double> &input) override;

    std::vector<double> backward_prop(const std::vector<double> &input, const std::vector<double> &dE) override;
};

struct ReLu : public AbstractActivationFunction {
    std::vector<double> forward_prop(const std::vector<double> &input) override;

    std::vector<double> backward_prop(const std::vector<double> &input, const std::vector<double> &dE) override;
};

struct Linear_function : public AbstractActivationFunction {
    std::vector<double> forward_prop(const std::vector<double> &input) override;

    std::vector<double> backward_prop(const std::vector<double> &input, const std::vector<double> &dE) override;
};

struct Cross_Entropy : public AbstractLossFunction {
    double forward_prop(const std::vector<double> &output, const std::vector<double> &test) override;

    std::vector<double> backward_prop(const std::vector<double> &output, const std::vector<double> &test) override;
};

struct Error_Squared : public AbstractLossFunction {
    double forward_prop(const std::vector<double> &output, const std::vector<double> &test) override;

    std::vector<double> backward_prop(const std::vector<double> &output, const std::vector<double> &test) override;
};

#endif
