#include "gestionObjet.hpp"

#include <iostream>
using namespace std;

GestionObjet::GestionObjet(int taille) {
    list = new Objet*[taille];
    for (int i = 0; i < taille ; i++) {
        list[i] = nullptr;
    }
    free = new int[taille];
    for (int i = 0; i < taille ; i++) {
        free[i] = 0;
    }
    this->taille = taille;
}
GestionObjet::~GestionObjet() {
    delete[] list;
    delete[] free;
}
void GestionObjet::ajouterObjet(Objet* objet,int index) {
    if (index < 0) {
        int ind = 0;
        while (ind < taille)
        {
            if(free[ind] == 0) {
                list[ind] = objet;
                free[ind] = 1;
                return;
            }
            ind++;
        }
        cout << "liste pleine\n";
        return;
    }
    if (index < taille) {
        if (free[index] == 1) delete list[index];
        list[index] = objet;
        free[index] = 1;
        return;
    }
    cout << "index invalide\n";
}
void GestionObjet::suprimerObjet(int index) {
    if(index >= taille) {cout << "index hors champ\n";return;}
    list[index] = nullptr;
    free[index] = 0;
}
void GestionObjet::afficherinfos() const {
    int count = 0;
    for (int i = 0; i < taille; i++)
    {
        if (free[i] == 1)
        {
            list[i]->afficheInfo();
            count++;
        }
    }
    cout << "je peux stocker encore " << taille - count << " objets\n";
}