#include "parcour3D.hpp"
#include <cmath>
#include <iostream>
using namespace std;

Parcour3D::Parcour3D(int nbPoint) : Parcour::Parcour(nbPoint) {}
Parcour3D::~Parcour3D() {}
float Parcour3D::calculDistance() const {
    if (tab.size() < 2) return 0.0f;
    float output = 0.;
    for (size_t i = 0; i + 1 < tab.size(); ++i) {
        float dx = tab[i + 1]->getX() - tab[i]->getX();
        float dy = tab[i + 1]->getY() - tab[i]->getY();
        float dz = tab[i + 1]->getZ() - tab[i]->getZ();
        output += std::hypot(dx, dy, dz);
    }
    return output;
}
void Parcour3D::message() const {
    cout << "je suis un parcour 3D\n";
}