#ifndef OPERATORFACTORY_HPP
#define OPERATORFACTORY_HPP
#include "tokenType.hpp"
#include "operatorType.hpp"
#include "expression.hpp"


class OperatorFactory {
public:
static Expression* build(TokenType tokenType, OperatorType operatorType);
};


#endif