#ifndef PARSER_HPP
#define PARSER_HPP
#include <stack>
#include <vector>
#include "token.hpp"
#include "expression.hpp"
#include "operatorFactory.hpp"


class Parser {
private:
std::stack<Expression*> operators;
std::stack<int> operands;
std::vector<Token*> tokens;
int idx;


public:
Parser(const std::vector<Token*> &tokens);
Token* next();
void rewind();
void reset();
int parse();
void consumeLeftParenthesis();
void consumeRightParenthesis();
bool consumeBinop();
bool consumeUnop();
bool consumeLitteral();
void consumeBaseExpression();
void consumeExpression();
void solve();
};


#endif