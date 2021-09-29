#ifndef NEURON_NETWORK_NETWORK_H
#define NEURON_NETWORK_NETWORK_H

#include "const.h"
#include "AbstractActivationFunction.h"
#include "random"


struct Network {
    std::vector<int> sizes = {N, K, K, N};
    std::vector<std::vector<double>> w[K - 1];
    std::vector<double> input[K], output[K];
    std::vector<AbstractActivationFunction *> function{K};

    Network();

    std::vector<double> Calc(std::vector<double> data);

    void Education(const std::vector<double> &data, const std::vector<double> &test);
};

#endif
