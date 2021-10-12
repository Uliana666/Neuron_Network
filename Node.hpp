#ifndef NEURON_NETWORK_NODE_HPP
#define NEURON_NETWORK_NODE_HPP
#include "Tensor.hpp"
template<CTensor T>
struct Node {
    T val{};
    T grad{0};

    virtual void Back() = 0;

    virtual ~Node() = default;
};

#endif
