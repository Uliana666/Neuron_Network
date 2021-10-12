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
    double &var;

    explicit variable(double & x) : var(x) {};

    void Calc() override {
        val = std::make_shared<valf>(var, grad);
    }
};

struct add : NodeTree {
    std::shared_ptr<NodeTree> child1, child2;

    add(std::shared_ptr<NodeTree> a, std::shared_ptr<NodeTree> b) : child1(std::move(a)), child2(std::move(b)) {}

    void Calc() override {
        child1->Calc(), child2->Calc();
        val = std::make_shared<addf>(child1->val, child2->val);
    }
};

struct sub : NodeTree {
    std::shared_ptr<NodeTree> child1, child2;

    sub(std::shared_ptr<NodeTree> a, std::shared_ptr<NodeTree> b) : child1(std::move(a)), child2(std::move(b)) {}

    void Calc() override {
        child1->Calc(), child2->Calc();
        val = std::make_shared<subf>(child1->val, child2->val);
    }
};

struct mul : NodeTree {
    std::shared_ptr<NodeTree> child1, child2;

    mul(std::shared_ptr<NodeTree> a, std::shared_ptr<NodeTree> b) : child1(std::move(a)), child2(std::move(b)) {}

    void Calc() override {
        child1->Calc(), child2->Calc();
        val = std::make_shared<mulf>(child1->val, child2->val);
    }
};

struct del : NodeTree {
    std::shared_ptr<NodeTree> child1, child2;

    del(std::shared_ptr<NodeTree> a, std::shared_ptr<NodeTree> b) : child1(std::move(a)), child2(std::move(b)) {}

    void Calc() override {
        child1->Calc(), child2->Calc();
        val = std::make_shared<delf>(child1->val, child2->val);
    }
};

struct poww : NodeTree {
    std::shared_ptr<NodeTree> child1, child2;

    poww(std::shared_ptr<NodeTree> a, std::shared_ptr<NodeTree> b) : child1(std::move(a)), child2(std::move(b)) {}

    void Calc() override {
        child1->Calc(), child2->Calc();
        val = std::make_shared<powff>(child1->val, child2->val);
    }
};

struct unSubb : NodeTree {
    std::shared_ptr<NodeTree> child;

    explicit unSubb(std::shared_ptr<NodeTree> a) : child(std::move(a)) {}

    void Calc() override {
        child->Calc();
        val = std::make_shared<unsubf>(child->val);
    }
};

struct expp : NodeTree {
    std::shared_ptr<NodeTree> child;

    explicit expp(std::shared_ptr<NodeTree> a) : child(std::move(a)) {}

    void Calc() override {
        child->Calc();
        val = std::make_shared<expff>(child->val);
    }
};


struct constant : NodeTree {
    double value;

    explicit constant(double x) : value(x) {}

    void Calc() override {
        val = std::make_shared<constf>(value);
    }
};


#endif
