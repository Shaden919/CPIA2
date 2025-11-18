#if !defined(DEF_GESTIONOBJET)
#define DEF_GESTIONOBJET

#include "objet.hpp"

class GestionObjet
{
private:
    int taille;
    int* free;
    Objet** list;
public:
    GestionObjet(int taille);
    ~GestionObjet();
    void ajouterObjet(Objet* objet,int index = -1);
    void suprimerObjet(int index);
    void afficherinfos() const;
};


#endif // DEF_GESTIONOBJET
