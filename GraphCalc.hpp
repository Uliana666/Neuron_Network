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

    void Back(double y) {
        child1->Back(y);
        child2->Back(y);
    }
};

struct subf : Node {
    std::shared_ptr<Node> child1, child2;

    subf(std::shared_ptr<Node> a, std::shared_ptr<Node> b) : child1(std::move(a)), child2(std::move(b)) {
        val = child1->val - child2->val;
    }

    void Back(double y) {
        child1->Back(y);
        child2->Back(-y);
    }
};

struct mulf : Node {
    std::shared_ptr<Node> child1, child2;

    mulf(std::shared_ptr<Node> a, std::shared_ptr<Node> b) : child1(std::move(a)), child2(std::move(b)) {
        val = child1->val * child2->val;
    }

    void Back(double y) {
        child1->Back(y * child2->val);
        child2->Back(y * child1->val);
    }
};

struct delf : Node {
    std::shared_ptr<Node> child1, child2;

    delf(std::shared_ptr<Node> a, std::shared_ptr<Node> b) : child1(std::move(a)), child2(std::move(b)) {
        val = child1->val / child2->val;
    }

    void Back(double y) {
        child1->Back(y / child2->val);
        child2->Back(-y / child1->val / child1->val);
    }
};

struct powff : Node {
    std::shared_ptr<Node> child1, child2;

    powff(std::shared_ptr<Node> a, std::shared_ptr<Node> b) : child1(std::move(a)), child2(std::move(b)) {
        val = pow(child1->val, child2->val);
    }

    void Back(double y) {
        child1->Back(y * (child2->val) * pow(child1->val, child2->val - 1));
        child2->Back(-y * val * log(child1->val));
    }
};

struct unsubf : Node {
    std::shared_ptr<Node> child;

    explicit unsubf(std::shared_ptr<Node> a) : child(std::move(a)) {
        val = -child->val;
    }

    void Back(double y) {
        child->Back(-y);
    }
};

struct expff : Node {
    std::shared_ptr<Node> child;

    explicit expff(std::shared_ptr<Node> a) : child(std::move(a)) {
        val = exp(child->val);
    }

    void Back(double y) {
        child->Back(y * val);
    }
};

struct valf : Node {
    double &grad;

    explicit valf(double x, double &where) : grad(where) {
        val = x;
    }

    void Back(double y) {
        grad += y;
    }
};

struct constf : Node {
    explicit constf(double x) {
        val = x;
    }

    void Back(double y) {}
};

#endif
