#include "../include/vehicule.hpp"

Vehicule::~Vehicule() {}

int Vehicule::getVitesse() const{
        return this->vitesse;
    }
void Vehicule::setVitesse(int vitesse) {
    if (vitesse > vitesseMax){this->vitesse = vitesseMax;return;}
    this->vitesse = vitesse;
    }
int Vehicule::getVitesseMax() const{
        return this->vitesseMax;
    }
int Vehicule::getAcceleration() const{
        return this->acceleration;
    }
void Vehicule::accelerer() {
        if (vitesse + acceleration >= vitesseMax) {vitesse = vitesseMax;return;}
        vitesse += acceleration;
    }