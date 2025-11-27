#if !defined(DEF_POLYNOMIAL)
#define DEF_POLYNOMIAL

#include "monomial.hpp"

template <int N, int M> class Polynomial : public Expression<N> {
protected:
  Monomial<N> *terms[M];

public:
  Polynomial(Monomial<N> *terms[M]) {
    for (int i = 0; i < M; ++i) {
      this->terms[i] = terms[i];
    }
  }
  term_t solve(term_t vals[N]) override {
    term_t result = 0.0f;

    for (int i = 0; i < M; i++) {
      result += terms[i]->solve(vals);
    }
    return result;
  }
  void differentiate(Expression<N> &exp, exp_t mask[N]) override {
    differentiate(dynamic_cast<Polynomial<N, M> &>(exp), mask);
  }
  void differentiate(Polynomial<N, M> &deriv, exp_t mask[N]) {
    for (int i = 0; i < M; ++i) {
      terms[i]->differentiate(*deriv.terms[i], mask);
    }
  }
  string toString() override {
    string result = "";

    if (M > 0) {
      for (int i = 0; i < (M - 1); ++i) {
        result += terms[i]->toString();
        if (terms[i]->getCoeff() >= 0) {
          result += "+";
        }
      }
      result += terms[M - 1]->toString();
    }
    return result;
  }
};

#endif // DEF_POLYNOMIAL
