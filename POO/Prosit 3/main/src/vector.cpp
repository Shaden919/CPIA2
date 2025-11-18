#include <iostream>
#include "vector.hpp"
#include <cmath>
using namespace std;

Vector::Vector(float x, float y){
    this->x = x;
    this->y = y;
}
Vector::~Vector(){}
void Vector::setX(float x){
    this->x = x;
}
void Vector::setY(float y){
    this->y = y;
}
float Vector::getX() const{
    return this->x;
}
float Vector::getY() const{
    return this->y;
}
double Vector::norm() const{
    return sqrt(this->x * this->x + this->y * this->y);
}
float Vector::dot(Vector vector) const{
    return this->x * vector.x + this->y * vector.y;
}
float Vector::cross(Vector vector) const{
    return (this->x * vector.y) - (this->y * vector.x);
}
Vector Vector::scalar(float scalar) const{
    Vector tmpVector(this->x * scalar,this->y * scalar);
    return tmpVector;
}
Vector Vector::negate() const{
    Vector tmpVector(this->x * -1,this->y * -1);
    return tmpVector;
}