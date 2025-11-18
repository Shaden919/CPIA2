#include "carre.hpp"
#include "rectangle.hpp"
#include "gestionObjet.hpp"
#include <iostream>
using namespace std;

int main() {
    Carre carre(5);
    Carre carre2(7);
    Rectangle rectangle(5,10);
    Rectangle rectangle2(3,9);
    Rectangle rectangle3(7,2);
    GestionObjet boite(6);
    boite.ajouterObjet(&carre);
    boite.ajouterObjet(&carre2,3);
    boite.ajouterObjet(&rectangle);
    boite.ajouterObjet(&rectangle2);
    boite.ajouterObjet(&rectangle3);
    boite.afficherinfos();
    return 0;
}