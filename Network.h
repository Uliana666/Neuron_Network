#ifndef NEURON_NETWORK_NETWORK_H
#define NEURON_NETWORK_NETWORK_H

#include "AbstractActivationFunction.h"
#include "AbstractLossFunction.h"
#include <random>
#include <memory>


struct Network {
    int cnt = 0;
    double speed = 0.5;
    size_t LAYERS;
    std::vector<size_t> sizes;
    std::vector<std::vector<std::vector<double>>> w{LAYERS - 1};
    std::vector<std::vector<double>> b{LAYERS};
    std::vector<std::vector<std::vector<double>>> w_gradient{LAYERS - 1};
    std::vector<std::vector<double>> b_gradient{LAYERS};
    std::vector<std::vector<double>> input{LAYERS}, output{LAYERS};
    std::vector<std::shared_ptr<AbstractActivationFunction>> function;
    std::shared_ptr<AbstractLossFunction> lossFunction;

    Network(size_t layers_, std::vector<size_t> size_layers, double speed_,
            std::vector<std::shared_ptr<AbstractActivationFunction>> func, std::shared_ptr<AbstractLossFunction> loss);

    std::vector<double> ForwardProp(std::vector<double> data);

    void BackwardProp(const std::vector<double> &test);

    void Learn(const std::vector<double>& data, const std::vector<double>& test);

    void Step();

    void MoveGradient(size_t num_lay, const std::vector<double> &lay, const std::vector<double> &output);
};

#endif
