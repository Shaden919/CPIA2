#include "bus.hpp"
#include <iostream>

void Bus::setSeat_capacity(int seat_capacity) {
    if (seat_capacity < 10 || seat_capacity > 50) {this->seat_capacity = 50; return;}
    this->seat_capacity = seat_capacity;
}
int Bus::getSeat_capacity() const {
    return this->seat_capacity;
}

void Bus::getInfo() const{
    std::cout << "Il s'agit d'un bus d'une capacité de " <<this->seat_capacity << " places, avec une vitesse maximale de "<<this->max_speed<<" kmh et son kilométrage est de "<<this->kilometrage<<" km.\n";
}

int Bus::countBigBus(Bus list[], int taille) {
    int count = 0;
    for (int i = 0; i < taille; i++) {
        if (list[i].Vehicule::getKilometrage() < 200000 &&
            list[i].getSeat_capacity() >= 40)
        {
            count++;
        }
    }
    return count;
}