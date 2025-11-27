#if !defined(DEF_EXPRESSION)
#define DEF_EXPRESSION

#include <cmath> 
#include <iostream>
#include <stdexcept> 
#include <vector>
#include <string>
using namespace std;

typedef float term_t;
typedef unsigned int exp_t;

template <int N> class Expression {
public:
  virtual term_t solve(term_t val[N]) = 0;
  virtual void differentiate(Expression<N> &exp, exp_t mask[N]) = 0;
  virtual string toString() = 0;
};

term_t power(term_t base, exp_t exp) {
  if (exp == 0)
    return 1.0f;

  for (exp_t i = 0; i < exp; ++i) {
    base *= base;
  }

  return base;
}

#endif // DEF_EXPRESSION
