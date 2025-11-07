#include <iostream>
#include "Circle.hpp"
#include <cmath>
using namespace std;

Circle::Circle() {
    cout << "Constructeur appelé" << endl;
}
Circle::Circle(double x, double y, double radius) {
    this->m_x = x;
    m_y = y;
    m_radius = radius;
    cout << "Constructeur appelé" << endl;
}
Circle::~Circle() {
    cout << "Destructeur appelé" << endl;
}
void Circle::setPosition(double x, double y) {
    m_x = x;
    m_y = y;
}
void Circle::setRadius(double radius) {
    m_radius = radius;
}
void Circle::printPosition() const {
    cout << "Circle's position: ("<< m_x << "," << m_y <<")" << endl;
}
double Circle::perimeter() const {
    return 2 * M_PI * m_radius;
}
double Circle::area() const {
    return m_radius * m_radius * M_PI;
}
