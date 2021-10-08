#ifndef NEURON_NETWORK_EXPRESSION_H
#define NEURON_NETWORK_EXPRESSION_H

#include <memory>
#include "NodeTree.h"
#include "Operations.hpp"
#include <unordered_map>

struct Expression {
    std::shared_ptr<NodeTree> root;

    Expression(std::shared_ptr<NodeTree> a) : root(a) {};

    double Evaluate(std::unordered_map<string, double> data = {}) {
        return root->Calc(data);
    }
};

Expression Add(Expression a, Expression b) {
    return Expression(std::shared_ptr<add_>(new add_(a.root, b.root)));
}

Expression Sub(Expression a, Expression b) {
    return Expression(std::shared_ptr<sub_>(new sub_(a.root, b.root)));
}

Expression Mul(Expression a, Expression b) {
    return Expression(std::shared_ptr<mul_>(new mul_(a.root, b.root)));
}

Expression Del(Expression a, Expression b) {
    return Expression(std::shared_ptr<del_>(new del_(a.root, b.root)));
}

Expression Pow(Expression a, Expression b) {
    return Expression(std::shared_ptr<pow_>(new pow_(a.root, b.root)));
}

Expression unSub(Expression a) {
    return Expression(std::shared_ptr<unSub_>(new unSub_(a.root)));
}

Expression Exp(Expression a) {
    return Expression(std::shared_ptr<exp_>(new exp_(a.root)));
}

Expression Variable(string s) {
    return Expression(std::shared_ptr<variable_>(new variable_(s)));
}

Expression Constant(double x) {
    return Expression(std::shared_ptr<constant_>(new constant_(x)));
}

#endif
