#include "Operations.h"
#include <cmath>
#include <memory>

Val::Val(double x) : x(x) {}

double Val::Calc() {
    return x;
}

Sum::Sum(std::shared_ptr<NodeTree> a, std::shared_ptr<NodeTree> b) : child1(a), child2(b) {}

double Sum::Calc() {
    return child1->Calc() + child2->Calc();
}

Sub::Sub(std::shared_ptr<NodeTree> a, std::shared_ptr<NodeTree> b) : child1(a), child2(b) {}

double Sub::Calc() {
    return child1->Calc() - child2->Calc();
}

Mul::Mul(std::shared_ptr<NodeTree> a, std::shared_ptr<NodeTree> b) : child1(a), child2(b) {}

double Mul::Calc() {
    return child1->Calc() * child2->Calc();
}

Del::Del(std::shared_ptr<NodeTree> a, std::shared_ptr<NodeTree> b) : child1(a), child2(b) {}

double Del::Calc() {
    return child1->Calc() / child2->Calc();
}

unSub::unSub(std::shared_ptr<NodeTree> a) : child(a) {}

double unSub::Calc() {
    return -child->Calc();
}

Exp::Exp(std::shared_ptr<NodeTree> a) : child(a) {}

double Exp::Calc() {
    return exp(child->Calc());
}
