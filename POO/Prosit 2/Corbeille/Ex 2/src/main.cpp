#include "file.hpp"

int main() {
    File fichier("Test","test.txt");
    fichier.write("coucou c'est moi, moumou la reine des mouettes !");
    fichier.read();
    return 0;
}