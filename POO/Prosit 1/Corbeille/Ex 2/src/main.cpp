#include <iostream>
#include "ListData.hpp"
using namespace std;

int main() {
    // a. Instanciation statique
    ListData maListe;

    // b. Ajouter 4 données à la liste (3, 9, 13, -1)
    maListe.AddData(3);
    maListe.AddData(9);
    maListe.AddData(13);
    maListe.AddData(-1);

    maListe.PrintData();

    maListe.MoyData();

    maListe.AddData(7);

    maListe.PrintData();

    maListe.MoyData();

    maListe.MinData();

    maListe.MaxData();

    maListe.VariationMax();

    return 0;
} // maListe.~ListData(); est appeller automatiquement 