#include "station.hpp"

Station::Station(int place) {
    parc = new Moto*[place];
    for (int i = 0; i < place; i++)
    {
        parc[i] = nullptr;
    }
    this->place = place;
}
Station::~Station() {
    for (int i = 0; i < place; i++)
    {
        delete parc[i];
    }
    delete[] parc;
}
void Station::add(int place,Moto* moto) {
    parc[place] = moto;
}
void Station::supr(int place) {
    delete parc[place];
    parc[place] = nullptr;
}
void Station::lavage() const {
    for (int i = 0; i < place; i++)
    {
        if (parc[i] != nullptr)
        {
            parc[i]->lave();
        }
        
    }
    
}