#include "file.hpp"
#include "crypt.hpp"

int main() {
    File fichier("test","test.txt");
    fichier.write("coucou c'est moi, moumou la reine des mouettes !");
    fichier.read();
    Crypt clee1("salut");
    Crypt clee2("chose");
    clee1.executeXOR(fichier);
    fichier.read();
    clee2.executeXOR(fichier,2);
    fichier.read();
    clee2.executeXOR(fichier);
    fichier.read();
    clee1.executeXOR(fichier,2);
    fichier.read();
    return 0;
}