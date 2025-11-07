#include <iostream>
#include "ListData.hpp"
using namespace std;

int main() {
    // a. Instanciation statique
    ListData maListe1;
    ListData maListe2;

    // b. Ajouter 4 données à la liste (3, 9, 13, -1)
    maListe1.AddData(3);
    maListe1.AddData(9);
    maListe1.AddData(13);
    maListe1.AddData(-1);

    maListe2.AddData(-5);
    maListe2.AddData(-2);
    maListe2.AddData(-7);
    maListe2.AddData(2);

    cout << "Moyenne de la première liste : ";
    maListe1.MoyData();

    cout << "Moyenne de la deuxième liste : ";
    maListe2.MoyData();

    return 0;
} // maListe.~ListData(); est appeller automatiquement 