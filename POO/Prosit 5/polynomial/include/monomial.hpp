#if !defined(DEF_MONOMIAL)
#define DEF_MONOMIAL

#include "expression.hpp"


template <int N> class Monomial : public Expression<N> {
protected:
  term_t coeff;
  exp_t exps[N];

  constexpr static exp_t null_exps[N] = {0};

public:
  Monomial() { nullify(); }
  Monomial(term_t coeff) : coeff(coeff) { setExponents(null_exps); }
  Monomial(term_t coeff, const exp_t exps[N]) : coeff(coeff) {
    setExponents(exps);
  }
  term_t getCoeff() { return coeff; }
  void getExponents(exp_t exps[N]) {
    for (int i = 0; i < N; ++i) {
      exps[i] = this->exps[i];
    }
  }
  void nullify() {
    coeff = 0.0f;
    for (int i = 0; i < N; ++i) {
      exps[i] = 0;
    }
  }
  void setExponents(const exp_t exps[N]) {
    for (int i = 0; i < N; ++i) {
      this->exps[i] = exps[i];
    }
  }
  void differentiate(Expression<N> &exp, exp_t mask[N]) override {
    differentiate(dynamic_cast<Monomial<N> &>(exp), mask);
  }
  void differentiate(Monomial<N> &deriv, exp_t mask[N]) {
    bool isConstant = 1;

    deriv = *this;
    for (int i = 0; i < N; ++i) {
      if (mask[i] * exps[i] != 0) {
        deriv.coeff *= exps[i];
        deriv.exps[i] -= 1;

        isConstant &= 0;
      }
    }
    if (isConstant)
      deriv.nullify();
  }
  term_t solve(term_t vals[N]) override {
    term_t result = coeff;

    for (int i = 0; i < N; ++i) {
      result *= power(vals[i], exps[i]);
    }
    return result;
  };
  virtual string toString() override {
    string result = to_string(coeff);
    for (int i = 0; i < N; ++i) {
      if (exps[i] != 0)
        result += "x_" + to_string(i + 1) + "^" + to_string(exps[i]);
    }
    return result;
  }
};

#endif // DEF_MONOMIAL
