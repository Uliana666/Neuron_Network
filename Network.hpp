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
/////
SigmoidBack sigmb;
SoftmaxBack sfmxb;
TanghBack tgntb;
LinearFunctionBack linrb;
ReLuBack relub;
CrossEntropyBack crs_eb;
ErrorSquaredBack er_sqb;


struct Network {
    int cnt = 0;
    double speed = 0.5;
    Tensor<double, 1, 2> in_data, out_data;
    Tensor<double, 1, 4> in_lay1, out_lay1, in_lay2, out_lay2;
    Tensor<double, 1, 2> in_lay3, out_lay3;
    Layer<2, 4> lay1{speed};
    Layer<4, 4> lay2{speed};
    Layer<4, 2> lay3{speed};

    Tensor<double, 1, 2> ForwardProp(Tensor<double, 1, 2> data) {
        in_data = data;
        ActivateInline(data, linr); ////
        out_data = data;
        in_lay1 = lay1.calc(data);
        auto data1 = Activate(lay1.calc(data), sigm); ////
        out_lay1 = data1;
        in_lay2 = lay2.calc(data1);
        auto data2 = Activate(lay2.calc(data1), sigm);  ////
        out_lay2 = data2;
        in_lay3 = lay3.calc(data2);
        auto data3 = Activate<1>(lay3.calc(data2), sfmx); ////
        out_lay3 = data3;
        return data3;
    }

    void BackwardProp(Tensor<double, 1, 2> test) {
        auto out = out_lay3;
        crs_eb(out, test); // 0
        //out *= Activate(in_lay3, relub); // 1
        out = sfmxb(out, in_lay3);
        auto out2 = lay3.calcb(out); // 2
        lay3.MoveGradient(out, out_lay2); // 3
        out2 *= Activate(in_lay2, sigmb); // 1
        auto out3 = lay2.calcb(out2); // 2
        lay2.MoveGradient(out2, out_lay1); // 3
        out3 *= Activate(in_lay1, sigmb); //1
        auto out4 = lay1.calcb(out3); //2 -- бесполезно
        lay1.MoveGradient(out3, out_data);
    }

    template<class T>
    void Learn(Tensor<T, 1, 2> &data, Tensor<T, 1, 2> &test) {
        ForwardProp(data);
        BackwardProp(test);
    }

    void Step() {
        lay1.Step(), lay2.Step(), lay3.Step();
    }

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
*/

#endif