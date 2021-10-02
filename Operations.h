#ifndef NEURON_NETWORK_OPERATIONS_H
#define NEURON_NETWORK_OPERATIONS_H

#include "NodeTree.h"

struct Val : NodeTree {
    double x;

    Val(double x);

    double Calc() override;
};

struct Sum : NodeTree {
    NodeTree *child1, *child2;

    Sum(NodeTree *a, NodeTree *b);

    double Calc() override;
};

struct Sub : NodeTree {
    NodeTree *child1, *child2;

    Sub(NodeTree *a, NodeTree *b);

    double Calc() override;
};

struct Mul : NodeTree {
    NodeTree *child1, *child2;

    Mul(NodeTree *a, NodeTree *b);

    double Calc() override;
};

struct Del : NodeTree {
    NodeTree *child1, *child2;

    Del(NodeTree *a, NodeTree *b);

    double Calc() override;
};

struct unSub : NodeTree {
    NodeTree *child;

    unSub(NodeTree *a);

    double Calc() override;
};

struct Exp : NodeTree {
    NodeTree *child;

    Exp(NodeTree *a);

    double Calc() override;
};


#endif
