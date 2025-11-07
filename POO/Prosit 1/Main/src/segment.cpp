#include <iostream>
#include <segment.hpp>
using namespace std;

Segment::Segment(Point origin, Vector direction){
    this->origin = origin;
    this->direction = direction;
}
Segment::~Segment(){}
float Segment::length() const{
    return this->direction.norm();
}
Point Segment::setOrigin(Point point){
    this->origin = point;
}
Point Segment::getOrigin() const{
    return this->origin;
}
Vector Segment::setDirection(Vector vector){
    this->direction = vector;
}
Vector Segment::getDirection() const{
    return this->direction;
}
IntersectionStatus Segment::intersect(Segment segment, Point point) const{
    
}