#ifndef BINARYOP_HPP
#define BINARYOP_HPP
#include "expression.hpp"


class BinaryOp : public Expression {
public:
virtual int compute(int left, int right) = 0;
virtual void* interpret() override;
};


class MinusBinaryOp : public BinaryOp {
public:
int compute(int left, int right) override;
};


class PlusBinaryOp : public BinaryOp {
public:
int compute(int left, int right) override;
};


class StarBinaryOp : public BinaryOp {
public:
int compute(int left, int right) override;
};


class DivBinaryOp : public BinaryOp {
public:
int compute(int left, int right) override;
};


#endif