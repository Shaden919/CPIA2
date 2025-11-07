#include "point.hpp"
#include <iostream>
using namespace std;

Point::Point(float x = 0, float y = 0){
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
float Point::getX() const{
    return this->x;
}
float Point::getY() const{
    return this->y;
}
float Point::print() const{
    cout << "(" << this->x << "," << this->y << ")" << endl;
}
Vector Point::minus(Point point) const{
    Vector tmpVector;

    tmpVector.setX(this->x - point.x);
    tmpVector.setY(this->y - point.y);
    
    return tmpVector;
}
Point Point::add(Point point) const{
    Point tmpPoint;

    tmpPoint.x = this->x + point.x;
    tmpPoint.y = this->y + point.y;
    
    return tmpPoint;
}