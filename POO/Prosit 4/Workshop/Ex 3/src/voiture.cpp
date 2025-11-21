#include "../include/voiture.hpp"
#include <iostream>
using namespace std;

Voiture::Voiture() {}
Voiture::~Voiture() {}
void Voiture::lave() const{
    cout << "voiture laver\n";
}