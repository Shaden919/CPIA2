#include "parcour.hpp"
#include <iostream>
using namespace std;

Parcour::Parcour(int nbPoint) {
    tab.reserve(nbPoint);
}
Parcour::~Parcour() {}
void Parcour::print() const {
    cout<<"ce parcour contient : \n";
    for (int i = 0; i < tab.size(); i++)
    {
        cout<<"   -  ";
        tab[i]->afficherCoordo();
    }
}
void Parcour::ajouterPoint(CLpoint* point) {
    tab.push_back(point);
}