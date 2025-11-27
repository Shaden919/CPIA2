#include "expression.hpp"
#include "monomial.hpp"
#include "polynomial.hpp"
#include "monomial1D.hpp"
#include "polynomial1D.hpp"

int main() {
  term_t vals[1] = {3.0f};
  const exp_t exps[3] = {2u,5u,3u};
  const exp_t exps2[3] = {2u,5u,0};
  const exp_t exps3[3] = {2u,0,0};
  exp_t mask[3] = {1,0,1};

  Monomial<3> m1(12.4f, exps);
  Monomial<3> m2(5,exps2);
  Monomial<3> m3(2,exps3);
  Monomial<3> dm;
  m1.differentiate(dm,mask);
  cout << dm.toString() << endl;
  Monomial<3>* terms[3] = {&m1,&m2,&m3};
  Polynomial<3,3> p1(terms);
  cout << p1.toString() << endl;

  Monomial<3> md1, md2, md3;
  Monomial<3>* dterms[3] = {&md1, &md2, &md3};

  Polynomial<3,3> dp(dterms);


  p1.differentiate(dp, mask);


  cout << dp.toString() << endl;
}