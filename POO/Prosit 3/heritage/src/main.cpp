#include "personnage.hpp"
#include "guerrier.hpp"
#include "magicien.hpp"

int main() {
    Personnage monPersonnage;
    Guerrier monGuerrier;
    monPersonnage.coupDePoing(monGuerrier);
    monGuerrier.coupDePoing(monPersonnage);
    Magicien mage("merlin");
    mage.sePresenter();
    monGuerrier.sePresenter();
}