#ifndef NEURON_NETWORK_EXPRESSIONTREE_H
#define NEURON_NETWORK_EXPRESSIONTREE_H

#include "NodeTree.h"
#include "Operations.h"
#include <memory>

struct ExpressionTree {
    std::shared_ptr<NodeTree> root;

    ExpressionTree(double x);

    ExpressionTree(std::shared_ptr<NodeTree> root);

    ExpressionTree operator+(const ExpressionTree &b);

    ExpressionTree operator-(const ExpressionTree &b);

    ExpressionTree operator*(const ExpressionTree &b);

    ExpressionTree operator/(const ExpressionTree &b);

    ExpressionTree exp();

    ExpressionTree operator-();

    void operator+=(const ExpressionTree &b);

    void operator-=(const ExpressionTree &b);

    void operator*=(const ExpressionTree &b);

    void operator/=(const ExpressionTree &b);
};


#endif
