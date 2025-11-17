#ifndef DEF_GUERRIER
#define DEF_GUERRIER
#include <iostream>
#include <string>

#include "personnage.hpp"//Ne pas oublier d’inclure Personnage.hpp pour pouvoir en hériter
class Guerrier : public Personnage//Signifie  : créer une classe Guerrier qui hérite de la classe Personnage
{
    public:    
        void frapperCommeUnSourdAvecUnMarteau() const;
        void sePresenter() const{
              std::cout << "Bonjour, je m’appelle " << m_nom << "." << std::endl;
              std::cout << "J’ai encore " << m_vie << " points de vie." << std::endl;  
              std::cout << "Je suis un guerrier redoutable." << std::endl;}
};

#endif