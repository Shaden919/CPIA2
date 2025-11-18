#include "point.hpp"
#include <iostream>
using namespace std;

Point::Point(float x, float y){
    this->x = x;
    this->y = y;
}
Point::~Point(){}
void Point::setX(float x){
     this->x = x;
}
void Point::setY(float y){
    this->y = y;
}
void Point::print() const{
    cout << "(" << this->x << "," << this->y << ")" << endl;
}
float Point::getX() const{
    return this->x;
}
float Point::getY() const{
    return this->y;
}
Vector Point::minus(Point point) const{
    Vector tmpVector;

    tmpVector.setX(this->x - point.x);
    tmpVector.setY(this->y - point.y);
    
    return tmpVector;
}
Point Point::add(Vector vector) const{
    Point tmpPoint;

    tmpPoint.x = this->x + vector.getX();
    tmpPoint.y = this->y + vector.getY();
    
    return tmpPoint;
}