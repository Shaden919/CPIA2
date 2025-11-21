#include "CLpoint3D.hpp"
#include <iostream>
using namespace std;
CLpoint3D::CLpoint3D(float x,float y, float z) : CLpoint(x,y) {
    this->z = z;
}
CLpoint3D::~CLpoint3D() {}
void CLpoint3D::setZ(float z) {
    this->z = z;
}
float CLpoint3D::getZ() const {
    return z;
}
void CLpoint3D::afficherCoordo() const {
    cout << "les coordonnees du point :" << this << ", de type : 2 sont {"<<this->getX()<<","<<this->getY()<<","<<this->getZ()<<"}\n";
}