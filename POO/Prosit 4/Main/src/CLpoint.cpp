#include "CLpoint.hpp"
#include <iostream>
using namespace std;

CLpoint::CLpoint(float x, float y) {
    this->x = x;
    this->y = y;
}
CLpoint::~CLpoint() {}
void CLpoint::setX(float x) {
    this->x = x;
}
void CLpoint::setY(float y) {
    this->y = y;
}
float CLpoint::getX() const {
    return x;
}
float CLpoint::getY() const {
    return y;
}
void CLpoint::afficherCoordo() const {
    cout << "les coordonnees du point :" << this << ", de type : 1 sont {"<<this->getX()<<","<<this->getY()<<"}\n";
}
void CLpoint::setZ(float) {}

float CLpoint::getZ() const {return 0.0f;}