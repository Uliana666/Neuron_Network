#include "Network.h"
#include "const.h"
#include "Functions.h"
#include <iostream>
#include <random>
#include <cassert>

std::mt19937 gen(777);
std::uniform_real_distribution<> dis(-0.5, 0.5);
Sigmoid sigm;
Softmax sfmx;
Tangent tgnt;
Linearf linr;
Cross_Entropy crs_e;
Error_Squared er_sq;

Network::Network() {
    for (int i = 0; i < LAYERS - 1; ++i) {
        w[i].resize(sizes[i], std::vector<double>(sizes[i + 1]));
        w_gradient[i].resize(sizes[i], std::vector<double>(sizes[i + 1], 0));
    }
    for (auto &i: w) for (auto &j: i) for (double &k: j) k = dis(gen);
    for (int i = 0; i < LAYERS; ++i)
        function[i] = &tgnt;
    function[LAYERS - 1] = &sfmx;
    //function[0] = &linr;
    lossFunction = &crs_e;
}

void Network::Move_grad(const int &num_lay, const std::vector<double> &lay, const std::vector<double> &output) {
    assert(lay.size() == sizes[num_lay + 1]);
    assert(output.size() == sizes[num_lay]);
    for (int j = 0; j < sizes[num_lay]; ++j)
        for (int k = 0; k < sizes[num_lay + 1]; ++k) {
            w_gradient[num_lay][j][k] += n * lay[k] * output[j];
        }
}

void Network::Step() {
    for (int i = 0; i < LAYERS - 1; ++i) {
        for (size_t j = 0; j < w[i].size(); ++j) {
            for (size_t k = 0; k < w[i][j].size(); ++k) {
                w[i][j][k] -= w_gradient[i][j][k] / step;
                w_gradient[i][j][k] = 0;
            }
        }
    }
}

std::vector<double> Network::Calc(std::vector<double> data) {
    for (int i = 0; i < LAYERS - 1; ++i) {
        input[i] = data;
        output[i] = data = function[i]->forward_prop(data);
        assert(output[i].size() == input[i].size());
        std::vector<double> in(sizes[i + 1], 0.);
        for (size_t j = 0; j < data.size(); ++j)
            for (int k = 0; k < sizes[i + 1]; ++k) {
                in[k] += data[j] * w[i][j][k];
            }
        data = in;
    }
    input[LAYERS - 1] = data;
    return (output[LAYERS - 1] = function[LAYERS - 1]->forward_prop(data));
}

void Network::Learn(const std::vector<double> &data, const std::vector<double> &test) {
    Calc(data);
    std::vector<double> lay = lossFunction->backward_prop(output[LAYERS - 1], test);
    for (int i = LAYERS - 2; i >= 0; --i) {
        lay = function[i + 1]->backward_prop(input[i + 1], lay);
        std::vector<double> lay2(sizes[i], 0.);
        for (int j = 0; j < sizes[i]; ++j)
            for (int k = 0; k < sizes[i + 1]; ++k)
                lay2[j] += lay[k] * w[i][j][k];
        Move_grad(i, lay, output[i]);
        lay = lay2;
    }
    if (++cnt == step) {
        cnt = 0;
        Step();
    }
}
