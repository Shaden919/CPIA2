#include "moto.hpp"
#include "voiture.hpp"
#include "station.hpp"

int main() {
    Station s1(3);
    Moto* m = new Moto;
    Moto* v1 = new Voiture;
    Moto* v2 = new Voiture;
    s1.add(0,m);
    s1.add(1,v1);
    s1.add(2,v2);
    s1.lavage();
    delete v1;
    v1 = new Moto;
    s1.lavage();
    return 0;
}