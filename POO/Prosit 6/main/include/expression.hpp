#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP


class Expression {
public:
virtual ~Expression() {}
virtual void* interpret() = 0;
};


#endif