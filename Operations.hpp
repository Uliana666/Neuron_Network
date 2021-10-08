#ifndef NEURON_NETWORK_OPERATIONS_HPP
#define NEURON_NETWORK_OPERATIONS_HPP

#include <cmath>
#include <memory>
#include <unordered_map>
#include <utility>
#include "NodeTree.h"
#include "Node.hpp"
#include "GraphCalc.hpp"

struct variable : NodeTree {
    string name;

    explicit variable(string s) : name(std::move(s)) {};

    std::shared_ptr<Node> Calc(const std::unordered_map<string, double> &data) override {
        return std::make_shared<valf>((*data.find(name)).second);
    }
};

struct add : NodeTree {
    std::shared_ptr<NodeTree> child1, child2;

    add(std::shared_ptr<NodeTree> a, std::shared_ptr<NodeTree> b) : child1(std::move(a)), child2(std::move(b)) {}

    std::shared_ptr<Node> Calc(const std::unordered_map<string, double> &data) override {
        return std::make_shared<addf>(child1->Calc(data), child2->Calc(data));
    }
};

struct sub : NodeTree {
    std::shared_ptr<NodeTree> child1, child2;

    sub(std::shared_ptr<NodeTree> a, std::shared_ptr<NodeTree> b) : child1(std::move(a)), child2(std::move(b)) {}

    std::shared_ptr<Node> Calc(const std::unordered_map<string, double> &data) override {
        return std::make_shared<subf>(child1->Calc(data), child2->Calc(data));
    }
};

struct mul : NodeTree {
    std::shared_ptr<NodeTree> child1, child2;

    mul(std::shared_ptr<NodeTree> a, std::shared_ptr<NodeTree> b) : child1(std::move(a)), child2(std::move(b)) {}

    std::shared_ptr<Node> Calc(const std::unordered_map<string, double> &data) override {
        return std::make_shared<mulf>(child1->Calc(data), child2->Calc(data));
    }
};

struct del : NodeTree {
    std::shared_ptr<NodeTree> child1, child2;

    del(std::shared_ptr<NodeTree> a, std::shared_ptr<NodeTree> b) : child1(std::move(a)), child2(std::move(b)) {}

    std::shared_ptr<Node> Calc(const std::unordered_map<string, double> &data) override {
        return std::make_shared<delf>(child1->Calc(data), child2->Calc(data));
    }
};

struct poww : NodeTree {
    std::shared_ptr<NodeTree> child1, child2;

    poww(std::shared_ptr<NodeTree> a, std::shared_ptr<NodeTree> b) : child1(std::move(a)), child2(std::move(b)) {}

    std::shared_ptr<Node> Calc(const std::unordered_map<string, double> &data) override {
        return std::make_shared<powff>(child1->Calc(data), child2->Calc(data));
    }
};

struct unSubb : NodeTree {
    std::shared_ptr<NodeTree> child;

    explicit unSubb(std::shared_ptr<NodeTree> a) : child(std::move(a)) {}

    std::shared_ptr<Node> Calc(const std::unordered_map<string, double> &data) override {
        return std::make_shared<unsubf>(child->Calc(data));
    }
};

struct expp : NodeTree {
    std::shared_ptr<NodeTree> child;

    explicit expp(std::shared_ptr<NodeTree> a) : child(std::move(a)) {}

    std::shared_ptr<Node> Calc(const std::unordered_map<string, double> &data) override {
        return std::make_shared<expff>(child->Calc(data));
    }
};


struct constant : NodeTree {
    double val;

    explicit constant(double x) : val(x) {}

    std::shared_ptr<Node> Calc(const std::unordered_map<string, double> &data) override {
        return std::make_shared<valf>(val);
    }
};


#endif
