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
};

struct subf : Node {
    std::shared_ptr<Node> child1, child2;

    subf(std::shared_ptr<Node> a, std::shared_ptr<Node> b) : child1(std::move(a)), child2(std::move(b)) {
        val = child1->val - child2->val;
    }
};

struct mulf : Node {
    std::shared_ptr<Node> child1, child2;

    mulf(std::shared_ptr<Node> a, std::shared_ptr<Node> b) : child1(std::move(a)), child2(std::move(b)) {
        val = child1->val * child2->val;
    }
};

struct delf : Node {
    std::shared_ptr<Node> child1, child2;

    delf(std::shared_ptr<Node> a, std::shared_ptr<Node> b) : child1(std::move(a)), child2(std::move(b)) {
        child1->val / child2->val;
    }
};

struct powff : Node {
    std::shared_ptr<Node> child1, child2;

    powff(std::shared_ptr<Node> a, std::shared_ptr<Node> b) : child1(std::move(a)), child2(std::move(b)) {
        val = pow(child1->val, child2->val);
    }
};

struct unsubf : Node {
    std::shared_ptr<Node> child;

    explicit unsubf(std::shared_ptr<Node> a) : child(std::move(a)){
        val = -child->val;
    }
};

struct expff : Node {
    std::shared_ptr<Node> child;

    explicit expff(std::shared_ptr<Node>  a) : child(std::move(a)){
        val = exp(child->val);
    }
};

struct valf : Node {

    explicit valf(double x){
        val = x;
    }
};

#endif
