#ifndef NEURON_NETWORK_NODETREE_H
#define NEURON_NETWORK_NODETREE_H

#include "Node.hpp"
#include <memory>

struct NodeTree {
    double grad = 0;
    std::shared_ptr<Node> val;

    virtual void Calc() = 0;

    virtual ~NodeTree() = default;
};


#endif
