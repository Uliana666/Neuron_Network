#ifndef NEURON_NETWORK_ABSTRACTLOSSFUNCTION_H
#define NEURON_NETWORK_ABSTRACTLOSSFUNCTION_H
#include <iostream>
#include <vector>

struct AbstractLossFunction {
    virtual double ForwardProp(const std::vector<double> &output, const std::vector<double> &test) = 0;

    virtual std::vector<double> BackwardProp(const std::vector<double> &output, const std::vector<double> &test) = 0;
};
#endif
