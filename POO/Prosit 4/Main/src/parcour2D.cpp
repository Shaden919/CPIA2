#include "parcour2D.hpp"
#include <cmath>
#include <iostream>
using namespace std;

Parcour2D::Parcour2D(int nbPoint) : Parcour::Parcour(nbPoint) {}
Parcour2D::~Parcour2D() {}
float Parcour2D::calculDistance() const {
    if (tab.size() < 2) return 0.0f;
    float output = 0.;
    for (size_t i = 0; i + 1 < tab.size(); ++i) {
        float dx = tab[i + 1]->getX() - tab[i]->getX();
        float dy = tab[i + 1]->getY() - tab[i]->getY();
        output += std::hypot(dx, dy);
    }
    return output;
}
void Parcour2D::message() const {
    cout << "je suis un parcour 2D\n";
}