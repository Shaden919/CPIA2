#include "voitureSport.hpp"
#include <iostream>
using namespace std;

VoitureSport::VoitureSport(int vitesseMax,int acceleration) {
    if (vitesseMax > 200) {this->vitesseMax = 200;}
    else this->vitesseMax = vitesseMax;
    if (acceleration > 8) {this->acceleration = 8;}
    else this->acceleration = acceleration;
}

VoitureSport::~VoitureSport() {}

void VoitureSport::setVitesseMax(int vitesseMax) {
    if (vitesseMax > 200) {this->vitesseMax = 200;return;}
    this->vitesseMax = vitesseMax;
}
void VoitureSport::setAcceleration(int acceleration) {
    if (acceleration > 8) {this->acceleration = 8;return;}
    this->acceleration = acceleration;
}

 void VoitureSport::affiche() const{
    cout << "je suis une voiture de sport\n";
 }
