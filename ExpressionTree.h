#ifndef NEURON_NETWORK_EXPRESSIONTREE_H
#define NEURON_NETWORK_EXPRESSIONTREE_H

#include "NodeTree.h"
#include "Operations.h"

struct ExpressionTree {
    NodeTree *root;

    ExpressionTree(double x);

    ExpressionTree(NodeTree *root);

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
