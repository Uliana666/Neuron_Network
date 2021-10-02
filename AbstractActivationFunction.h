#ifndef NEURON_NETWORK_ABSTRACTACTIVATIONFUNCTION_H
#define NEURON_NETWORK_ABSTRACTACTIVATIONFUNCTION_H

#include <iostream>
#include <vector>
#include <memory>

struct AbstractActivationFunction {
    virtual std::vector<double> ForwardProp(const std::vector<double> &input) = 0;

    virtual std::vector<double> BackwardProp(const std::vector<double> &input, const std::vector<double> &dE) = 0;

    virtual ~AbstractActivationFunction() {}

};


#endif
