#ifndef NEURON_NETWORK_NETWORK_H
#define NEURON_NETWORK_NETWORK_H

#include "const.h"
#include "AbstractActivationFunction.h"
#include "AbstractLossFunction.h"
#include "random"


struct Network {
    int step = 10, cnt = 0;
    std::vector<int> sizes = {N, K, K, N};
    std::vector<std::vector<double>> w[LAYERS - 1];
    std::vector<std::vector<double>> w_gradient[LAYERS - 1];
    std::vector<double> input[LAYERS], output[LAYERS];
    std::vector<AbstractActivationFunction *> function{LAYERS};
    AbstractLossFunction *lossFunction;

    Network();

    std::vector<double> Calc(std::vector<double> data);

    void Learn(const std::vector<double> &data, const std::vector<double> &test);

    void Step();

    void Move_grad(const int& num_lay,const std::vector<double>& lay, const std::vector<double>& output);
};

#endif
