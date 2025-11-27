#ifndef LEXER_HPP
#define LEXER_HPP
#include <vector>
#include <string>
#include "token.hpp"


class Lexer {
private:
int readInteger(const std::string &expr, std::string &num);
public:
std::vector<Token*> tokenize(const std::string &expr);
};


#endif