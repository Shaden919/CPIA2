#if !defined(DEF_POLYNOMIAL1D)
#define DEF_POLYNOMIAL1D

#include "polynomial.hpp"

template <int M> class Polynomial1D : public Polynomial<1, M> {
public:
  Polynomial1D(Monomial1D *mons[M]) : Polynomial<1, M>((Monomial<1> **)mons) {}
};

#endif // DEF_POLYNOMIAL1D
