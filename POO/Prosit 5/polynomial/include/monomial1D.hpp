#if !defined(DEF_MONOMIAL1D)
#define DEF_MONOMIAL1D

#include "monomial.hpp"

const int N = 1;
class Monomial1D : public Monomial<N> {
public:
  Monomial1D() : Monomial() {}
  // this could be a constant
  Monomial1D(term_t coeff) : Monomial(coeff) {}
  Monomial1D(term_t coeff, const exp_t exps[N]) : Monomial(coeff, exps) {}
};



#endif // DEF_MONOMIAL1D
