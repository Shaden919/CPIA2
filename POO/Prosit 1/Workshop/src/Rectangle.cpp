#include <iostream>
#include "Rectangle.hpp"
#include <cmath>
using namespace std;

Rectangle::Rectangle(){
    cout << "Constructeur appelé" << endl;
}
Rectangle::Rectangle(double x, double y, double width, double height){
    m_x = x;
    m_y = y;
    m_width = width;
    m_height = height;
    cout << "Constructeur appelé" << endl;
}
Rectangle::~Rectangle(){
    cout << "Destructeur appelé" << endl;
}
void Rectangle:: setPosition(double x, double y){
    m_x = x;
    m_y = y;
}
void Rectangle::setWidth(double width){
    m_width = width;
}
void Rectangle::setHeight(double height){
    m_height = height;
}
void Rectangle::printPosition() const{
    cout << "Rectangle's position: ("<< m_x << "," << m_y <<")" << endl;
}
double Rectangle::perimeter() const{
    return 2*m_height + 2*m_width;
}
double Rectangle::area() const{
    return m_height * m_width;
}