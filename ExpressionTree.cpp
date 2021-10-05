#include "ExpressionTree.h"
#include "Operations.h"

ExpressionTree::ExpressionTree(double x) : root(std::make_shared<Val>(x)) {}

ExpressionTree::ExpressionTree(std::shared_ptr<NodeTree> root) : root(root) {}

ExpressionTree ExpressionTree::operator+(const ExpressionTree &b) {
    return ExpressionTree(std::make_shared<Sum>(root, b.root));
}

ExpressionTree ExpressionTree::operator-(const ExpressionTree &b) {
    return ExpressionTree(std::make_shared<Sub>(root, b.root));
}

ExpressionTree ExpressionTree::operator*(const ExpressionTree &b) {
    return ExpressionTree(std::make_shared<Mul>(root, b.root));
}

ExpressionTree ExpressionTree::operator/(const ExpressionTree &b) {
    return ExpressionTree(std::make_shared<Del>(root, b.root));
}

ExpressionTree ExpressionTree::exp() {
    return ExpressionTree(std::make_shared<Exp>(root));
}

ExpressionTree ExpressionTree::operator-() {
    return ExpressionTree(std::make_shared<unSub>(root));
}

void ExpressionTree::operator+=(const ExpressionTree &b) {
    root = std::make_shared<Sum>(root, b.root);
}

void ExpressionTree::operator-=(const ExpressionTree &b) {
    root = std::make_shared<Sub>(root, b.root);
}

void ExpressionTree::operator*=(const ExpressionTree &b) {
    root = std::make_shared<Mul>(root, b.root);
}

void ExpressionTree::operator/=(const ExpressionTree &b) {
    root = std::make_shared<Del>(root, b.root);
}


