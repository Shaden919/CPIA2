#include "vehicule.hpp"
#include <iostream>
using namespace std;

void Vehicule::setMax_speed(int max_speed) {
    if (max_speed < 200 ) {this->max_speed = 240;return;}
    this->max_speed = max_speed;
}
void Vehicule::setkilometrage(int kilometrage) {
    if (kilometrage < 0 ) {this->kilometrage = 0;return;}
    this->kilometrage = kilometrage;
}
int Vehicule::getMax_speed() const {
    return this->max_speed;
}
int Vehicule::getKilometrage() const {
    return this->kilometrage;   
}