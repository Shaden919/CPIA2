#include "point.hpp"
#include "vector.hpp"
#include "segment.hpp"
#include "polygone.hpp"
#include "cerlce.hpp"
#include <cstdlib>
#include <iostream>

int main() {
  Point p1(0.,0.), p2(1.,2.);
  Vector vector(4.,5.);
  Cerlce cercle(&p1,5);
  cercle.afficheInfo();
  p1 = p1.add(vector);
  cercle.afficheInfo();
}