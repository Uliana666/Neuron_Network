#ifndef NEURON_NETWORK_ABSTRACTLOSSFUNCTION_H
#define NEURON_NETWORK_ABSTRACTLOSSFUNCTION_H
#include <iostream>
#include <vector>

struct AbstractLossFunction {
    virtual double forward_prop(const std::vector<double> &output, const std::vector<double> &test) = 0;

    virtual std::vector<double> backward_prop(const std::vector<double> &output, const std::vector<double> &test) = 0;
};
#endif
