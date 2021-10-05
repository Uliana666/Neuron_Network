#ifndef NEURON_NETWORK_OPERATIONS_H
#define NEURON_NETWORK_OPERATIONS_H

#include "NodeTree.h"
#include <memory>

struct Val : NodeTree {
    double x;

    Val(double x);

    double Calc() override;
};

struct Sum : NodeTree {
    std::shared_ptr<NodeTree> child1, child2;

    Sum(std::shared_ptr<NodeTree> a, std::shared_ptr<NodeTree> b);

    double Calc() override;
};

struct Sub : NodeTree {
    std::shared_ptr<NodeTree> child1, child2;

    Sub(std::shared_ptr<NodeTree> a, std::shared_ptr<NodeTree> b);

    double Calc() override;
};

struct Mul : NodeTree {
    std::shared_ptr<NodeTree> child1, child2;

    Mul(std::shared_ptr<NodeTree> a, std::shared_ptr<NodeTree> b);

    double Calc() override;
};

struct Del : NodeTree {
    std::shared_ptr<NodeTree> child1, child2;

    Del(std::shared_ptr<NodeTree> a, std::shared_ptr<NodeTree> b);

    double Calc() override;
};

struct unSub : NodeTree {
    std::shared_ptr<NodeTree> child;

    unSub(std::shared_ptr<NodeTree> a);

    double Calc() override;
};

struct Exp : NodeTree {
    std::shared_ptr<NodeTree> child;

    Exp(std::shared_ptr<NodeTree> a);

    double Calc() override;
};


#endif
