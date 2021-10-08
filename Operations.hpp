#ifndef NEURON_NETWORK_OPERATIONS_H
#define NEURON_NETWORK_OPERATIONS_H

#include <cmath>
#include <memory>
#include <unordered_map>

struct variable_ : NodeTree {
    string name;

    variable_(string s) : name(s) {};

    double Calc(const std::unordered_map<string, double> &data) override {
        return (*data.find(name)).second;
    }
};

struct add_ : NodeTree {
    std::shared_ptr<NodeTree> child1, child2;

    add_(std::shared_ptr<NodeTree> a, std::shared_ptr<NodeTree> b) : child1(a), child2(b) {}

    double Calc(const std::unordered_map<string, double> &data) override {
        return child1->Calc(data) + child2->Calc(data);
    }
};

struct sub_ : NodeTree {
    std::shared_ptr<NodeTree> child1, child2;

    sub_(std::shared_ptr<NodeTree> a, std::shared_ptr<NodeTree> b) : child1(a), child2(b) {}

    double Calc(const std::unordered_map<string, double> &data) override {
        return child1->Calc(data) - child2->Calc(data);
    }
};

struct mul_ : NodeTree {
    std::shared_ptr<NodeTree> child1, child2;

    mul_(std::shared_ptr<NodeTree> a, std::shared_ptr<NodeTree> b) : child1(a), child2(b) {}

    double Calc(const std::unordered_map<string, double> &data) override {
        return child1->Calc(data) * child2->Calc(data);
    }
};

struct del_ : NodeTree {
    std::shared_ptr<NodeTree> child1, child2;

    del_(std::shared_ptr<NodeTree> a, std::shared_ptr<NodeTree> b) : child1(a), child2(b) {}

    double Calc(const std::unordered_map<string, double> &data) override {
        return child1->Calc(data) / child2->Calc(data);
    }
};

struct unSub_ : NodeTree {
    std::shared_ptr<NodeTree> child;

    unSub_(std::shared_ptr<NodeTree> a) : child(a) {}

    double Calc(const std::unordered_map<string, double> &data) override {
        return -child->Calc(data);
    }
};

struct exp_ : NodeTree {
    std::shared_ptr<NodeTree> child;

    exp_(std::shared_ptr<NodeTree> a) : child(a) {}

    double Calc(const std::unordered_map<string, double> &data) override {
        return exp(child->Calc(data));
    }
};

struct pow_ : NodeTree {
    std::shared_ptr<NodeTree> child1, child2;

    pow_(std::shared_ptr<NodeTree> a, std::shared_ptr<NodeTree> b) : child1(a), child2(b) {}

    double Calc(const std::unordered_map<string, double> &data) override {
        return pow(child1->Calc(data), child2->Calc(data));
    }
};

struct constant_ : NodeTree {
    double val;

    constant_(double x) : val(x) {}

    double Calc(const std::unordered_map<string, double> &data) override {
        return val;
    }
};


#endif
