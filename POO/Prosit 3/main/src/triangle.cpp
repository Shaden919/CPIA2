#include "triangle.hpp"
#include <iostream>
using namespace std;

Triangle::Triangle(Point* origine,Vector aileDroite,Vector aileGauche) : aileDroite(aileDroite),aileGauche(aileGauche){
    this->origine = origine;
}
Triangle::~Triangle() {}
double Triangle::aire() const {
    return aileDroite.getX() * aileGauche.getY() - aileDroite.getY() * aileGauche.getX() / 2;
}
void Triangle::setAileDroite(Vector aileDrtoie) {
    this->aileDroite = aileDroite;
}
void Triangle::setAileGauche(Vector aileGauche) {
    this->aileGauche = aileGauche;
}
Vector Triangle::getAileDroite() const {
    return this->aileDroite;
}
Vector Triangle::getAilegauche() const {
    this->aileGauche;
}
double Triangle::perimeter() const {
    Point p1 = origine->add(aileDroite);
    Point p2 = origine->add(aileGauche);
    return aileDroite.norm() + aileGauche.norm() + (p1.minus(p2)).norm();
}
void Triangle::afficheInfo() const {
    Point p1 = origine->add(aileDroite);
    Point p2 = origine->add(aileGauche);
    cout << "je suis un rectangle de cote 1 : " << aileDroite.norm() << ", cote 2 : " << aileGauche.norm() << ", cote 3 : " << (p1.minus(p2)).norm() << "\n";
    cout << "mes sommets sont {"<< origine->getX() << ","<< origine->getY() << "} " << "{"<< p1.getX() << ","<< p1.getY() << "} " << "{"<< p2.getX() << ","<< p2.getY() << "}\n";
}