#ifndef TOKEN_HPP
#define TOKEN_HPP
#include <string>
#include "tokenType.hpp"


class Token {
private:
TokenType type;
std::string value;
public:
Token(TokenType type, const std::string &value);
std::string getValue() const;
TokenType getType() const;
bool isType(TokenType t) const;
bool isOperator() const;
std::string toString() const;
};


#endif