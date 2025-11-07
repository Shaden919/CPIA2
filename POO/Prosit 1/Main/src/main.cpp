#include "point.hpp"
#include "vector.hpp"
#include "segment.hpp"
#include <cstdlib>

int main() {
  Point p1(0.,0.), p2(1.,2.);
  Vector v1(1.,1.), v2(2.,4.);
  Segment s1(p1,v1), s2(p1,v1);

  return EXIT_SUCCESS;
}