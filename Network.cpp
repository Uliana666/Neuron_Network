#include "Network.h"
#include "Functions.h"
#include <iostream>
#include <random>
#include <utility>
#include "ExpressionTree.h"

Network::Network(size_t layers_, std::vector<size_t> size_layers, double speed_,
                 std::vector<std::shared_ptr<AbstractActivationFunction>> func, std::shared_ptr<AbstractLossFunction> loss) :
        LAYERS(layers_), sizes(std::move(size_layers)), speed(speed_), function(std::move(func)), lossFunction(loss) {
    std::mt19937 gen(777);
    std::uniform_real_distribution<> dis(-0.5, 0.5);
    for (int i = 0; i < LAYERS - 1; ++i) {
        w[i].resize(sizes[i], std::vector<double>(sizes[i + 1]));
        w_gradient[i].resize(sizes[i], std::vector<double>(sizes[i + 1], 0));
    }
   for (int i = 0; i < LAYERS; ++i) {
        b[i].resize(sizes[i]);
        b_gradient[i].resize(sizes[i], 0);
    }
    for (auto &i: w) for (auto &j: i) for (double &k: j) k = dis(gen);
    for (auto &i: b) for (double &j: i) j = dis(gen);

}

void Network::Move_gradient(size_t num_lay, const std::vector<double> &lay, const std::vector<double> &output) {
    ++cnt;
    for (size_t j = 0; j < sizes[num_lay]; ++j)
        for (size_t k = 0; k < sizes[num_lay + 1]; ++k)
            w_gradient[num_lay][j][k] += lay[k] * output[j];
    for (size_t j = 0; j < sizes[num_lay + 1]; ++j)
        b_gradient[num_lay + 1][j] += lay[j];
}

void Network::Step() {
    if (!cnt) return;
    for (size_t i = 0; i < LAYERS - 1; ++i)
        for (size_t j = 0; j < w[i].size(); ++j)
            for (size_t k = 0; k < w[i][j].size(); ++k) {
                w[i][j][k] -= speed * w_gradient[i][j][k] / cnt;
                w_gradient[i][j][k] = 0;
            }
    for (size_t i = 0; i < LAYERS; ++i)
        for (size_t j = 0; j < b[i].size(); ++j) {
            b[i][j] -= speed * b_gradient[i][j] / cnt;
            b_gradient[i][j] = 0;
        }
    cnt = 0;
}

std::vector<double> Network::Calc(std::vector<double> data) {
    for (int i = 0; i < LAYERS - 1; ++i) {
        input[i] = data;
        output[i] = data = function[i]->forward_prop(data);
        std::vector<double> in(sizes[i + 1], 0.);
        for (size_t j = 0; j < data.size(); ++j)
            for (size_t k = 0; k < sizes[i + 1]; ++k) {
                in[k] += data[j] * w[i][j][k];
            }
        for (size_t j = 0; j < sizes[i + 1]; ++j) in[j] += b[i + 1][j];
        data = in;
    }
    input[LAYERS - 1] = data;
    return (output[LAYERS - 1] = function[LAYERS - 1]->forward_prop(data));
}

void Network::BackwardProp(const std::vector<double> &data, const std::vector<double> &test) {
    Calc(data);
    std::vector<double> lay = lossFunction->backward_prop(output[LAYERS - 1], test);
    for (int i = LAYERS - 2; i >= 0; --i) {
        lay = function[i + 1]->backward_prop(input[i + 1], lay);
        std::vector<double> lay2(sizes[i], 0.);
        for (int j = 0; j < sizes[i]; ++j)
            for (int k = 0; k < sizes[i + 1]; ++k)
                lay2[j] += lay[k] * w[i][j][k];
        Move_gradient(i, lay, output[i]);
        lay = lay2;
    }
}
