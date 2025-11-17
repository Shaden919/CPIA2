#ifndef DEF_MAGICIEN
#define DEF_MAGICIEN
#include <iostream>
#include <string>
#include "personnage.hpp"

class Magicien : public Personnage{  
    public:    
        Magicien() : Personnage(), m_mana(100){}
        Magicien(std::string nom) : Personnage(nom), m_mana(100){}
        void bouleDeFeu(Personnage cible) const;    
        void bouleDeGlace(Personnage cible) const; 
    private:    
        int m_mana;
    };
#endif