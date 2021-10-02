#include "Operations.h"
#include <cmath>

Val::Val(double x) : x(x) {}

double Val::Calc() {
    return x;
}

Sum::Sum(NodeTree *a, NodeTree *b) : child1(a), child2(b) {}

double Sum::Calc() {
    return child1->Calc() + child2->Calc();
}

Sub::Sub(NodeTree *a, NodeTree *b) : child1(a), child2(b) {}

double Sub::Calc() {
    return child1->Calc() - child2->Calc();
}

Mul::Mul(NodeTree *a, NodeTree *b) : child1(a), child2(b) {}

double Mul::Calc() {
    return child1->Calc() * child2->Calc();
}

Del::Del(NodeTree *a, NodeTree *b) : child1(a), child2(b) {}

double Del::Calc() {
    return child1->Calc() / child2->Calc();
}

unSub::unSub(NodeTree *a) : child(a) {}

double unSub::Calc() {
    return -child->Calc();
}

Exp::Exp(NodeTree *a) : child(a) {}

double Exp::Calc() {
    return exp(child->Calc());
}
