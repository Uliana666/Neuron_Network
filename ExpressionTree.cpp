#include "ExpressionTree.h"
#include "Operations.h"

ExpressionTree::ExpressionTree(double x) : root(new Val(x)) {}

ExpressionTree::ExpressionTree(NodeTree *root) : root(root) {}

ExpressionTree ExpressionTree::operator+(const ExpressionTree &b) {
    return ExpressionTree(new Sum(root, b.root));
}

ExpressionTree ExpressionTree::operator-(const ExpressionTree &b) {
    return ExpressionTree(new Sub(root, b.root));
}

ExpressionTree ExpressionTree::operator*(const ExpressionTree &b) {
    return ExpressionTree(new Mul(root, b.root));
}

ExpressionTree ExpressionTree::operator/(const ExpressionTree &b) {
    return ExpressionTree(new Del(root, b.root));
}

ExpressionTree ExpressionTree::exp() {
    return ExpressionTree(new Exp(root));
}

ExpressionTree ExpressionTree::operator-() {
    return ExpressionTree(new unSub(root));
}

void ExpressionTree::operator+=(const ExpressionTree &b) {
    root = new Sum(root, b.root);
}

void ExpressionTree::operator-=(const ExpressionTree &b) {
    root = new Sub(root, b.root);
}

void ExpressionTree::operator*=(const ExpressionTree &b) {
    root = new Mul(root, b.root);
}

void ExpressionTree::operator/=(const ExpressionTree &b) {
    root = new Del(root, b.root);
}


