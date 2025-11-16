#include "file.hpp"

int main() {
    File fichier("Test","test.txt");
    fichier.writeBin("coucou c'est moi, moumou la reine des mouettes !");
    fichier.readBin();
    return 0;
}