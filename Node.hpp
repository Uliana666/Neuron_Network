#ifndef NEURON_NETWORK_NODE_HPP
#define NEURON_NETWORK_NODE_HPP

struct Node {
    double val{};
    double grad = 0;

    virtual void Back() = 0;

    virtual ~Node() = default;
};

#endif
