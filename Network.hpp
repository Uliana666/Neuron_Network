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

template<size_t deep>
struct Network {
    double speed = 0.00003;
    Tensor<double, deep, 2> out_data;
    Tensor<double, deep, 4> in_lay1, out_lay1, in_lay2, out_lay2;
    Tensor<double, deep, 2> in_lay3, out_lay3;
    Layer<2, 4> lay1{speed};
    Layer<4, 4> lay2{speed};
    Layer<4, 2> lay3{speed};

    Tensor<double, 1, 2> Calc(Tensor<double, 1, 2> &data) {
        ActivateInline(data, linr);
        auto data1 = Activate(lay1.calc(data), tgnt);
        auto data2 = Activate(lay2.calc(data1), tgnt);
        auto data3 = Activate<1>(lay3.calc(data2), sfmx);
        return data3;
    }

    Tensor<double, deep, 2> ForwardProp(Tensor<double, deep, 2> &data) {
        ActivateInline(data, linr);
        out_data = data;
        in_lay1 = lay1.calc(data);
        auto data1 = Activate(in_lay1, tgnt);
        out_lay1 = data1;
        in_lay2 = lay2.calc(data1);
        auto data2 = Activate(in_lay2, tgnt);
        out_lay2 = data2;
        in_lay3 = lay3.calc(data2);
        auto data3 = Activate<1>(in_lay3, sfmx);
        out_lay3 = data3;
        return data3;
    }

    void BackwardProp(const Tensor<double, deep, 2> &test) {
        auto out = out_lay3;
        crs_eb(out, test);
        //out *= Activate(in_lay3, sigmb); // 1
        //out = sfmxb(out, in_lay3);
        auto res = out;
        res.fill(0);
        sfmxb(out, in_lay3, res);
        auto out2 = lay3.calcb(res);
        lay3.MoveGradient(out, out_lay2);
        out2 *= Activate(in_lay2, tgntb);
        auto out3 = lay2.calcb(out2);
        lay2.MoveGradient(out2, out_lay1);
        out3 *= Activate(in_lay1, tgntb);
        lay1.MoveGradient(out3, out_data);
    }

    template<class T>
    void Learn(Tensor<T, deep, 2> data, const Tensor<T, deep, 2> &test, double &kek) {
        ForwardProp(data);
        kek += crs_e(out_lay3, test);
        BackwardProp(test);
    }

    void Step() {
        lay1.Step(), lay2.Step(), lay3.Step();
    }

};


#endif