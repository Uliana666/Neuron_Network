#include "Network.h"
#include "const.h"
#include "Functions.h"
#include <iostream>
#include <random>

std::mt19937 gen(777);
std::uniform_real_distribution<> dis(-0.5, 0.5);
Sigmoid sigm;
Softmax sfmx;
Tangent tgnt;
Linearf linr;
Cross_Entropy crs_e;
Error_Squared er_sq;

Network::Network() {
    w[0].resize(N, std::vector<double>(K));
    w_gradient[0].resize(N, std::vector<std::vector<double>>(K));
    w[1].resize(K, std::vector<double>(K));
    w_gradient[1].resize(K, std::vector<std::vector<double>>(K));
    w[2].resize(K, std::vector<double>(N));
    w_gradient[2].resize(K, std::vector<std::vector<double>>(K));
    for (auto &i: w) for (auto &j: i) for (double &k: j) k = dis(gen);
    for (auto &i: w_gradient) for (auto &j: i) for (auto &k: j) k.resize(step, 0);
    for (int i = 0; i < K - 1; ++i)
        function[i] = &tgnt;
    function[K - 1] = &sfmx;
    lossFunction = &crs_e;
}

void Network::Upgrade() {
    for (int i = 0; i < K - 1; ++i) {
        for (size_t j = 0; j < w[i].size(); ++j) {
            for (size_t k = 0; k < w[i][j].size(); ++k) {
                for (auto g: w_gradient[i][j][k])
                    w[i][j][k] -= g / step;
            }
        }
    }
}

std::vector<double> Network::Calc(std::vector<double> data) {
    for (int i = 0; i < K - 1; ++i) {
        input[i] = data;
        data = function[i]->forward_prop(data);
        output[i] = data;
        std::vector<double> in(sizes[i + 1], 0.l);
        for (size_t j = 0; j < data.size(); ++j)
            for (int k = 0; k < sizes[i + 1]; ++k) {
                in[k] += data[j] * w[i][j][k];
            }
        data = in;
    }
    input[K - 1] = data;
    return function[K - 1]->forward_prop(data);
}

void Network::Learn(const std::vector<double> &data, const std::vector<double> &test) {
    output[K - 1] = Calc(data);
    std::vector<double> lay = lossFunction->backward_prop(output[K - 1], test);
    for (int i = K - 2; i >= 0; --i) {
        lay = function[i + 1]->backward_prop(input[i + 1], lay);
        std::vector<double> lay2(sizes[i], 0.);
        for (int j = 0; j < sizes[i]; ++j)
            for (int k = 0; k < sizes[i + 1]; ++k)
                lay2[j] += lay[k] * w[i][j][k];
        for (int j = 0; j < sizes[i]; ++j)
            for (int k = 0; k < sizes[i + 1]; ++k) {
                w_gradient[i][j][k][cnt] = n * lay[k] * output[i][j];
            }
        lay = lay2;
    }
    if (++cnt == step) {
        cnt = 0;
        Upgrade();
    }
}
