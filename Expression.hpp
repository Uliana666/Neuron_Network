#ifndef NEURON_NETWORK_EXPRESSION_HPP
#define NEURON_NETWORK_EXPRESSION_HPP

#include <memory>
#include "NodeTree.h"
#include "Operations.hpp"
#include <unordered_map>
#include <utility>
#include <memory>
#include "GraphCalc.hpp"
#include "Node.hpp"

struct Expression {
    std::shared_ptr<NodeTree> root;

    Expression(std::shared_ptr<NodeTree>  a) : root(std::move(a)) {};

    shared_ptr<Node> Evaluate(const std::unordered_map<string, double>& data = {}) {
        return root->Calc(data);
    }
};

Expression Add(const Expression& a, const Expression& b) {
    return {std::make_shared<add>(a.root, b.root)};
}

Expression Sub(const Expression& a, const Expression& b) {
    return {std::make_shared<sub>(a.root, b.root)};
}

Expression Mul(const Expression& a, const Expression& b) {
    return {std::make_shared<mul>(a.root, b.root)};
}

Expression Del(const Expression& a, const Expression& b) {
    return {std::make_shared<del>(a.root, b.root)};
}

Expression Pow(const Expression& a, const Expression& b) {
    return {std::make_shared<poww>(a.root, b.root)};
}

Expression unSub(const Expression& a) {
    return {std::make_shared<unSubb>(a.root)};
}

Expression Exp(const Expression& a) {
    return {std::make_shared<expp>(a.root)};
}

Expression Variable(const string& s) {
    return {std::make_shared<variable>(s)};
}

Expression Constant(double x) {
    return {std::make_shared<constant>(x)};
}

#endif
