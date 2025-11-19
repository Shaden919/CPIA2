#include "cerlce.hpp"
#include <cmath>
#include <iostream>

Cerlce::Cerlce(Point *origine,double rayon) {
    this->origine = origine;
    if (rayon < 0){this->rayon = -rayon;return;}
    this->rayon = rayon;
    
}
Cerlce::~Cerlce() {}
void Cerlce::setOrigine(Point* origine) {
    this->origine = origine;
}
Point Cerlce::getOrigine() const {
    return *origine;
}
void Cerlce::setRayon(double rayon) {
    if (rayon < 0){this->rayon = -rayon;return;}
    this->rayon = rayon;
}
double Cerlce::getRayon() const {
    return this->rayon;
}
double Cerlce::aire() const{
    return M_PI * rayon * rayon;
}
double Cerlce::perimeter() const{
    return M_PI * 2 * rayon;
}
void Cerlce::afficheInfo() const{
    std::cout << "je suis un cercle d'origine : " << this->origine->getX() << "," << this->origine->getY() << " et de rayon : " << this->rayon << std::endl;
}