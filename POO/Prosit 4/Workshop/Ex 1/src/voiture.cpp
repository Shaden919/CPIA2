#include "voiture.hpp"
#include <iostream>
using namespace std;

Voiture::Voiture(int vitessemax,int acceleration) {
    if (vitesseMax > 100) {this->vitesseMax = 100;}
    else this->vitesseMax = vitesseMax;
    if (acceleration > 3) {this->acceleration = 3;}
    else this->acceleration = acceleration;
}

Voiture::~Voiture() {}

void Voiture::setVitesseMax(int vitesseMax) {
    if (vitesseMax > 100) {this->vitesseMax = 100;return;}
    this->vitesseMax = vitesseMax;
}
void Voiture::setAcceleration(int acceleration) {
    if (acceleration > 3) {this->acceleration = 3;return;}
    this->acceleration = acceleration;
}
void Voiture::affiche() const {
    cout << "je suis une voiture\n";   
}