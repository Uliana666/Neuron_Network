#ifndef NEURON_NETWORK_GRAPHCALC_HPP
#define NEURON_NETWORK_GRAPHCALC_HPP

#include "Node.hpp"
#include <memory>
#include <utility>
#include "Apply.hpp"

template<CTensor T>

struct variable : Node<T> {

    explicit variable(T x) {
        Node<T>::val = x;
    }

    void Back() override {}
};

template<CTensor T, CTensor T1, CTensor T2>
struct add : Node<T> {
    std::shared_ptr<Node<T1>> child1;
    std::shared_ptr<Node<T2>> child2;

    add(std::shared_ptr<Node<T1>> a, std::shared_ptr<Node<T2>> b) : child1(std::move(a)), child2(std::move(b)) {
        Node<T>::val = child1->val + child2->val;
    }

    void Back() override {
        if constexpr(T1::dim == 0) child1->grad += Node<T>::grad.SumElement();
        else child1->grad += Node<T>::grad;
        if constexpr(T2::dim == 0) child2->grad += Node<T>::grad.SumElement();
        else child2->grad += Node<T>::grad;
        child1->Back(), child2->Back();
    }
};

template<CTensor T, CTensor T1, CTensor T2>

struct sub : Node<T> {
    std::shared_ptr<Node<T1>> child1;
    std::shared_ptr<Node<T2>> child2;

    sub(std::shared_ptr<Node<T1>> a, std::shared_ptr<Node<T2>> b) : child1(std::move(a)), child2(std::move(b)) {
        Node<T>::val = child1->val - child2->val;
    }

    void Back() override {
        if constexpr(T1::dim == 0) child1->grad += Node<T>::grad.SumElement();
        else child1->grad += Node<T>::grad;
        if constexpr(T2::dim == 0) child2->grad -= Node<T>::grad.SumElement();
        else child2->grad -= Node<T>::grad;
        child1->Back(), child2->Back();
    }
};

template<CTensor T, CTensor T1, CTensor T2>

struct mul : Node<T> {
    std::shared_ptr<Node<T1>> child1;
    std::shared_ptr<Node<T2>> child2;

    mul(std::shared_ptr<Node<T1>> a, std::shared_ptr<Node<T2>> b) : child1(std::move(a)), child2(std::move(b)) {
        Node<T>::val = child1->val * child2->val;
    }

    void Back() override {
        if constexpr(T1::dim == 0) child1->grad += (Node<T>::grad * child2->val).SumElement();
        else child1->grad += Node<T>::grad * child2->val;
        if constexpr(T2::dim == 0) child2->grad += (Node<T>::grad * child1->val).SumElement();
        else child2->grad += Node<T>::grad * child1->val;
        child1->Back(), child2->Back();
    }
};

template<CTensor T, CTensor T1, CTensor T2>

struct del : Node<T> {
    std::shared_ptr<Node<T1>> child1;
    std::shared_ptr<Node<T2>> child2;

    del(std::shared_ptr<Node<T1>> a, std::shared_ptr<Node<T2>> b) : child1(std::move(a)), child2(std::move(b)) {
        Node<T>::val = child1->val / child2->val;
    }

    void Back() override {
        if constexpr(T1::dim == 0) child1->grad += (Node<T>::grad / child2->val).SumElement();
        else child1->grad += Node<T>::grad / child2->val;
        if constexpr(T2::dim == 0) child2->grad -= (Node<T>::grad / child1->val / child1->val).SumElement();
        else child2->grad -= Node<T>::grad / child1->val / child1->val;
        child1->Back(), child2->Back();
    }
};

template<CTensor T, CTensor T1, class C>

struct pow_f : Node<T> {
    std::shared_ptr<Node<T1>> child1;
    std::shared_ptr<Node<Tensor<C>>> child2;

    pow_f(std::shared_ptr<Node<T1>> a, std::shared_ptr<Node<Tensor<C>>> b) : child1(std::move(a)),
                                                                             child2(std::move(b)) {
        Node<T>::val = pow(child1->val, child2->val);
    }

    void Back() override {
        child1->grad += Node<T>::grad * (child2->val) * pow(child1->val, child2->val - 1.);
        child2->grad += (Node<T>::grad * Node<T>::val * Activate(child1->val, logl)).SumElement();
        child1->Back(), child2->Back();
    }
};

template<CTensor T>

struct unsub : Node<T> {
    std::shared_ptr<Node<T>> child;

    explicit unsub(std::shared_ptr<Node<T>> a) : child(std::move(a)) {
        Node<T>::val = -child->val;
    }

    void Back() override {
        child->grad += -Node<T>::grad;
        child->Back();
    }
};

template<CTensor T>

struct exp_f : Node<T> {
    std::shared_ptr<Node<T>> child;

    explicit exp_f(std::shared_ptr<Node<T>> a) : child(std::move(a)) {
        Node<T>::val = Activate(child->val, expl);
    }

    void Back() override {
        child->grad += Node<T>::grad * Node<T>::val;
        child->Back();
    }
};


#endif
