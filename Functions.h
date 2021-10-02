#ifndef NEURON_NETWORK_FUNCTIONS_H
#define NEURON_NETWORK_FUNCTIONS_H

#include "AbstractActivationFunction.h"
#include "AbstractLossFunction.h"
#include <iostream>
#include <vector>

struct Sigmoid : public AbstractActivationFunction {
    static double calc(const double &x);

    std::vector<double> forward_prop(const std::vector<double> &input) override;

    std::vector<double> backward_prop(const std::vector<double> &input, const std::vector<double> &dE) override;
};

class Softmax : public AbstractActivationFunction {
    std::vector<double> forward_prop(const std::vector<double> &input) override;

    std::vector<double> backward_prop(const std::vector<double> &input, const std::vector<double> &dE) override;
};

class Tangent : public AbstractActivationFunction {
    static double calc(const double &x);

    std::vector<double> forward_prop(const std::vector<double> &input) override;

    std::vector<double> backward_prop(const std::vector<double> &input, const std::vector<double> &dE) override;
};
class ReLu : public AbstractActivationFunction {
    std::vector<double> forward_prop(const std::vector<double> &input) override;

    std::vector<double> backward_prop(const std::vector<double> &input, const std::vector<double> &dE) override;
};

class Linear_function : public AbstractActivationFunction {
    std::vector<double> forward_prop(const std::vector<double> &input) override;

    std::vector<double> backward_prop(const std::vector<double> &input, const std::vector<double> &dE) override;
};

class Cross_Entropy : public AbstractLossFunction {
    double forward_prop(const std::vector<double> &output, const std::vector<double> &test) override;

    std::vector<double> backward_prop(const std::vector<double> &output, const std::vector<double> &test) override;
};
class Error_Squared : public AbstractLossFunction {
    double forward_prop(const std::vector<double> &output, const std::vector<double> &test) override;

    std::vector<double> backward_prop(const std::vector<double> &output, const std::vector<double> &test) override;
};

#endif
