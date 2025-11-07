#include <iostream>
//#include "Circle.hpp"
//#include "Rectangle.hpp"
#include "Fraction.hpp"
using namespace std;

int main() {
 /*Circle c{0, 0, 1};
 cout << c.perimeter() << endl;
 c.setPosition(1, 1);
 c.printPosition();
 cout << "Area of the circle: ("<< c.area() <<")" << endl;
 Rectangle r{0, 0, 1, 2};
 cout << r.perimeter() << endl;
 r.setPosition(-1, -1);
 r.printPosition();
 cout << "Area of the rectangle: ("<< r.area() <<")" << endl;
 return 0;*/


 Fraction f0;

 if (f0.getNumerateur() == 1 && f0.getDenominateur() == 1) {
 cout << "[OK] Default constructor works" << endl;
 }else {
 cout << "[FAILURE] Default constructor doesn't work" << endl;
 }

 Fraction f1(1, 2);

 if (f1.getNumerateur() == 1 && f1.getDenominateur() == 2) {
 cout << "[OK] Constructor with parameters works" << endl;
 }else {
 cout << "[FAILURE] Constructor with parameters doesn't work" << endl;
 }

 Fraction f2(3, 4);

 /* Test add */ 

 Fraction f3 = f1.add(f2);

 if (f3.getNumerateur() == 10 && f3.getDenominateur() == 8) {
 cout << "[OK] Add method works" << endl;
 }else {
 cout << "[FAILURE] Add method doesn't work" << endl;
 }

 /* Test minus */

 f3 = f1.minus(f2);

 if (f3.getNumerateur() == -2 && f3.getDenominateur() == 8) {
 cout << "[OK] Minus method works" << endl;
 }else {
 cout << "[FAILURE] Minus method doesn't work" << endl;
 }
 /* Test multiply */

 f3 = f1.multiply(f2);

 if (f3.getNumerateur() == 3 && f3.getDenominateur() == 8) {
 cout << "[OK] Multiply method works" << endl;
 }else {
cout << "[FAILURE] Multiply method doesn't work" << endl;
 }

 /* Test divide */
 f3 = f1.divide(f2);
 
 if (f3.getNumerateur() == 4 && f3.getDenominateur() == 6) {
 cout << "[OK] Divide method works" << endl;
 }else {
 cout << "[FAILURE] Divide method doesn't work" << endl;
 }
  
 Fraction f4(21,15);
 f4.simplify();
 if (f4.getNumerateur() == 7 && f4.getDenominateur() == 5) {
 cout << "[OK] Simplify method works" << endl;
 }else {
 cout << "[FAILURE] Simplify method doesn't work" << endl;
 }

 return 0;
}