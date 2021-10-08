#ifndef NEURON_NETWORK_NODE_HPP
#define NEURON_NETWORK_NODE_HPP

struct Node {
    double val{};

    virtual void Back(double y) = 0;

    virtual ~Node() = default;
};

#endif
