#include "../include/vehicule.hpp"
#include "../include/voiture.hpp"
#include "../include/voitureSport.hpp"



void print(Vehicule const& v) {
    v.affiche();
}

int main() {
    Voiture v1;
    VoitureSport v2;
    print(v1);
    print(v2);
    return 0;
}