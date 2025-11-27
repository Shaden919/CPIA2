#ifndef UNARYOP_HPP
#define UNARYOP_HPP
#include "expression.hpp"


class UnaryOp : public Expression {
public:
virtual int compute(int right) = 0;
virtual void* interpret() override;
};


class MinusUnaryOp : public UnaryOp {
public:
int compute(int right) override;
};


class PlusUnaryOp : public UnaryOp {
public:
int compute(int right) override;
};


#endif