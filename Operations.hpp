#ifndef NEURON_NETWORK_OPERATIONS_H
#define NEURON_NETWORK_OPERATIONS_H

#include <cmath>
#include <memory>
#include <unordered_map>
#include <utility>
#include "NodeTree.h"

struct variable : NodeTree {
    string name;

    explicit variable(string s) : name(std::move(s)) {};

    double Calc(const std::unordered_map<string, double> &data) override {
        return (*data.find(name)).second;
    }
};

struct add : NodeTree {
    std::shared_ptr<NodeTree> child1, child2;

    add(std::shared_ptr<NodeTree> a, std::shared_ptr<NodeTree> b) : child1(std::move(a)), child2(std::move(b)) {}

    double Calc(const std::unordered_map<string, double> &data) override {
        return child1->Calc(data) + child2->Calc(data);
    }
};

struct sub : NodeTree {
    std::shared_ptr<NodeTree> child1, child2;

    sub(std::shared_ptr<NodeTree> a, std::shared_ptr<NodeTree> b) : child1(std::move(a)), child2(std::move(b)) {}

    double Calc(const std::unordered_map<string, double> &data) override {
        return child1->Calc(data) - child2->Calc(data);
    }
};

struct mul : NodeTree {
    std::shared_ptr<NodeTree> child1, child2;

    mul(std::shared_ptr<NodeTree> a, std::shared_ptr<NodeTree> b) : child1(std::move(a)), child2(std::move(b)) {}

    double Calc(const std::unordered_map<string, double> &data) override {
        return child1->Calc(data) * child2->Calc(data);
    }
};

struct del : NodeTree {
    std::shared_ptr<NodeTree> child1, child2;

    del(std::shared_ptr<NodeTree> a, std::shared_ptr<NodeTree> b) : child1(std::move(a)), child2(std::move(b)) {}

    double Calc(const std::unordered_map<string, double> &data) override {
        return child1->Calc(data) / child2->Calc(data);
    }
};

struct poww : NodeTree {
    std::shared_ptr<NodeTree> child1, child2;

    poww(std::shared_ptr<NodeTree> a, std::shared_ptr<NodeTree> b) : child1(std::move(a)), child2(std::move(b)) {}

    double Calc(const std::unordered_map<string, double> &data) override {
        return pow(child1->Calc(data), child2->Calc(data));
    }
};

struct unSub : NodeTree {
    std::shared_ptr<NodeTree> child;

    explicit unSub(std::shared_ptr<NodeTree> a) : child(std::move(a)) {}

    double Calc(const std::unordered_map<string, double> &data) override {
        return -child->Calc(data);
    }
};

struct expp : NodeTree {
    std::shared_ptr<NodeTree> child;

    explicit expp(std::shared_ptr<NodeTree> a) : child(std::move(a)) {}

    double Calc(const std::unordered_map<string, double> &data) override {
        return exp(child->Calc(data));
    }
};


struct constant : NodeTree {
    double val;

    explicit constant(double x) : val(x) {}

    double Calc(const std::unordered_map<string, double> &data) override {
        return val;
    }
};


#endif
