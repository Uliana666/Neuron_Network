#include "Network.h"
#include "const.h"
#include "Functions.h"
#include <iostream>
#include <random>

std::mt19937 gen(777);
std::uniform_real_distribution<> dis(0.0, 0.5);
Sigmoid sigm;
Softmax sfmx;

Network::Network() {
    w[0].resize(N, std::vector<double>(K));
    w[1].resize(K, std::vector<double>(K));
    w[2].resize(K, std::vector<double>(N));
    for (auto &i: w) for (auto &j: i) for (double &k: j) k = dis(gen);
    for (int i = 0; i < K - 1; ++i)
        function[i] = &sigm;
    function[K - 1] = &sfmx;
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

void Network::Education(const std::vector<double> &data, const std::vector<double> &test) {
    output[K - 1] = Calc(data);
    std::vector<double> lay(N);
    for (int i = 0; i < N; ++i) lay[i] = output[K - 1][i] - test[i];
    for (int i = K - 2; i >= 0; --i) {
        lay = function[i + 1]->backward_prop(input[i + 1], lay);
        std::vector<double> lay2(sizes[i], 0.);
        for (int j = 0; j < sizes[i]; ++j)
            for (int k = 0; k < sizes[i + 1]; ++k)
                lay2[j] += lay[k] * w[i][j][k];
        for (int j = 0; j < sizes[i]; ++j)
            for (int k = 0; k < sizes[i + 1]; ++k) {
                if (i != K - 2) w[i][j][k] -= n * lay[k] * output[i][j];
                else w[i][j][k] -= n2 * lay[k] * output[i][j];
            }
        lay = lay2;
    }
}
