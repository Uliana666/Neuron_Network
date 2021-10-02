#ifndef NEURON_NETWORK_ABSTRACTACTIVATIONFUNCTION_H
#define NEURON_NETWORK_ABSTRACTACTIVATIONFUNCTION_H

#include <iostream>
#include <vector>

struct AbstractActivationFunction {
    virtual std::vector<double> forward_prop(const std::vector<double> &input) = 0;

    virtual std::vector<double> backward_prop(const std::vector<double> &input, const std::vector<double> &dE) = 0;

    virtual ~AbstractActivationFunction() {}
};


#endif
