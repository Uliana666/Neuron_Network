#ifndef NEURON_NETWORK_AUTOGRADOPERATIONS_HPP
#define NEURON_NETWORK_AUTOGRADOPERATIONS_HPP

#include "memory"
#include "GraphCalc.hpp"

template<CTensor T>
std::shared_ptr<Node<T>> CreateAuto(T x) {
    return std::make_shared<variable<T>>(x);
}

template<CTensor T, CTensor T1, CTensor T2>
std::shared_ptr<Node<T>> operator+(std::shared_ptr<Node<T1>> a, std::shared_ptr<Node<T2>> b) {
    return std::make_shared<add<T, T1, T2>>(a, b);
}

template<CTensor T, CTensor T1>
std::shared_ptr<Node<T>> Add_b(std::shared_ptr<Node<T>> a, std::shared_ptr<Node<T1>> b) {
    return std::make_shared<add_b<T, T1>>(a, b);
}

template<CTensor T, CTensor T1, CTensor T2>
std::shared_ptr<Node<T>> operator-(std::shared_ptr<Node<T1>> a, std::shared_ptr<Node<T2>> b) {
    return std::make_shared<sub<T, T1, T2>>(a, b);
}

template<CTensor T, CTensor T1, CTensor T2>
std::shared_ptr<Node<T>> operator*(std::shared_ptr<Node<T1>> a, std::shared_ptr<Node<T2>> b) {
    return std::make_shared<mul<T, T1, T2>>(a, b);
}

template<CTensor T, CTensor T1, CTensor T2>
std::shared_ptr<Node<T>> operator/(std::shared_ptr<Node<T1>> a, std::shared_ptr<Node<T2>> b) {
    return std::make_shared<del<T, T1, T2>>(a, b);
}

template<CTensor T, CTensor T1, class C = double>
std::shared_ptr<Node<T>> pow(std::shared_ptr<Node<T1>> a, std::shared_ptr<Node<Tensor<C>>> b) {
    return std::make_shared<pow_f<T, T1, C>>(a, b);
}

template<CTensor T>
std::shared_ptr<Node<T>> operator-(std::shared_ptr<Node<T>> a) {
    return std::make_shared<unsub<T>>(a);
}

template<CTensor T>
std::shared_ptr<Node<T>> exp(std::shared_ptr<Node<T>> a) {
    return std::make_shared<exp<T>>(a);
}

template<class T, size_t len1, size_t k, size_t len2>
std::shared_ptr<Node<T>>
MultyMatrix(std::shared_ptr<Node<Tensor<T, len1, k>>> a, std::shared_ptr<Node<Tensor<T, k, len2>>> b) {
    return std::make_shared<multy_matrix<T, len1, k, len2>>(a, b);
}

template<CTensor T, class TFunction>
std::shared_ptr<Node<T>> function(std::shared_ptr<Node<T>> a, TFunction &f) {
    return std::make_shared<Function<T, TFunction>>(a, f);
}

template<CTensor T, class TFunction>
std::shared_ptr<Node<T>> function_loss(std::shared_ptr<Node<T>> out, std::shared_ptr<Node<T>> test, TFunction &f) {
    return std::make_shared<FunctionLoss<T, TFunction>>(out, test, f);
}

#endif
