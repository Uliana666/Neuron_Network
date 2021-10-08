#ifndef NEURON_NETWORK_NODETREE_H
#define NEURON_NETWORK_NODETREE_H

#include "Node.hpp"
#include <memory>

struct NodeTree {
    double grad = 0;

    virtual std::shared_ptr<Node> Calc(const std::unordered_map<string, double> &data) = 0;

    virtual ~NodeTree() = default;
};


#endif
