#ifndef NEURON_NETWORK_GRAPHCALC_HPP
#define NEURON_NETWORK_GRAPHCALC_HPP

#include "Node.hpp"
#include <memory>
#include <utility>

struct addf : Node {
    std::shared_ptr<Node> child1, child2;

    addf(std::shared_ptr<Node> a, std::shared_ptr<Node> b) : child1(std::move(a)), child2(std::move(b)) {
        val = child1->val + child2->val;
    }

    void Back() override {
        child1->grad += grad;
        child2->grad += grad;
        child1->Back(), child2->Back();
    }
};

struct subf : Node {
    std::shared_ptr<Node> child1, child2;

    subf(std::shared_ptr<Node> a, std::shared_ptr<Node> b) : child1(std::move(a)), child2(std::move(b)) {
        val = child1->val - child2->val;
    }

    void Back() override {
        child1->grad += grad;
        child2->grad += -grad;
        child1->Back(), child2->Back();
    }
};

struct mulf : Node {
    std::shared_ptr<Node> child1, child2;

    mulf(std::shared_ptr<Node> a, std::shared_ptr<Node> b) : child1(std::move(a)), child2(std::move(b)) {
        val = child1->val * child2->val;
    }

    void Back() override {
        child1->grad += grad * child2->val;
        child2->grad += grad * child1->val;
        child1->Back(), child2->Back();
    }
};

struct delf : Node {
    std::shared_ptr<Node> child1, child2;

    delf(std::shared_ptr<Node> a, std::shared_ptr<Node> b) : child1(std::move(a)), child2(std::move(b)) {
        val = child1->val / child2->val;
    }

    void Back() override {
        child1->grad += grad / child2->val;
        child2->grad += -grad / child1->val / child1->val;
        child1->Back(), child2->Back();
    }
};

struct powff : Node {
    std::shared_ptr<Node> child1, child2;

    powff(std::shared_ptr<Node> a, std::shared_ptr<Node> b) : child1(std::move(a)), child2(std::move(b)) {
        val = pow(child1->val, child2->val);
    }

    void Back() override {
        child1->grad += grad * (child2->val) * pow(child1->val, child2->val - 1);
        child2->grad += -grad * val * log(child1->val);
        child1->Back(), child2->Back();
    }
};

struct unsubf : Node {
    std::shared_ptr<Node> child;

    explicit unsubf(std::shared_ptr<Node> a) : child(std::move(a)) {
        val = -child->val;
    }

    void Back() override {
        child->grad += -grad;
        child->Back();
    }
};

struct expff : Node {
    std::shared_ptr<Node> child;

    explicit expff(std::shared_ptr<Node> a) : child(std::move(a)) {
        val = exp(child->val);
    }

    void Back() override {
        child->grad += grad * val;
        child->Back();
    }
};

struct valf : Node {
    double &gradient;

    explicit valf(double x, double &where) : gradient(where) {
        val = x;
    }

    void Back() override { gradient += grad; }
};

struct constf : Node {
    explicit constf(double x) {
        val = x;
    }

    void Back() override {}
};

#endif
