#ifndef NEURON_NETWORK_NETWORK_H
#define NEURON_NETWORK_NETWORK_H

#include <random>
#include <memory>
#include "Layer.hpp"
#include <array>
#include "Functions.hpp"
#include <iostream>
#include <random>
#include <utility>
#include <memory>
#include "ExpressionTree.h"

using namespace std;
Sigmoid sigm;
Softmax sfmx;
Tangh tgnt;
LinearFunction linr;
ReLu relu;
CrossEntropy crs_e;
ErrorSquared er_sq;


struct Network {
    int cnt = 0;
    double speed = 0.5;
    Layer<2, 4> lay1;
    Layer<4, 4> lay2;
    Layer<4, 2> lay3;

   /* Tensor<double, 1, 2> ForwardProp(Tensor<double, 1, 2> data) {
        ActivateInline(data, tgnt);
        auto data1 = Activate(lay1.calc(data), tgnt);
        auto data2 = Activate(lay2.calc(data1), tgnt);
        auto data3 = Activate(lay3.calc(data2), tgnt);
        return data3;
    }*/

    //void BackwardProp(const std::vector<double> &test);

    //void Learn(const std::vector<double> &data, const std::vector<double> &test);

    //void Step();

    //void MoveGradient(size_t num_lay, const std::vector<double> &lay, const std::vector<double> &output);
};

/*
void Network::MoveGradient(size_t num_lay, const std::vector<double> &lay, const std::vector<double> &output) {
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


void Network::Learn(const std::vector<double> &data, const std::vector<double> &test) {
    ForwardProp(data);
    BackwardProp(test);
}

void Network::BackwardProp(const std::vector<double> &test) {
    std::vector<double> lay = lossFunction->BackwardProp(output[LAYERS - 1], test);
    for (int i = LAYERS - 2; i >= 0; --i) {
        lay = function[i + 1]->BackwardProp(input[i + 1], lay);
        std::vector<double> lay2(sizes[i], 0.);
        for (int j = 0; j < sizes[i]; ++j)
            for (int k = 0; k < sizes[i + 1]; ++k)
                lay2[j] += lay[k] * w[i][j][k];
        MoveGradient(i, lay, output[i]);
        lay = lay2;
    }
}

*/
#endif