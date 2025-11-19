#include "../include/carre.hpp"
#include <iostream>
using namespace std;

Carre::Carre(Point* origine, Vector cote)
  : Rectangle(origine, cote, Vector(cote.getY(), -cote.getX())) {}
Carre::~Carre() {}
void Carre::afficheInfo() const {
    Point p1 = origine->add(longueur);
    Point p2 = origine->add(largeur);
    Point p3 = (origine->add(largeur)).add(longueur);
    cout << "je suis un carre de coter : " << longueur.norm() << "\n";
    cout << " mes sommets sont {" << origine->getX() << "," << origine->getY() << "} {" << p1.getX() << "," << p1.getY() << "} {" << p2.getX() << "," << p2.getY() <<"} {" << p3.getX() << "," << p3.getY() << "}\n";
}