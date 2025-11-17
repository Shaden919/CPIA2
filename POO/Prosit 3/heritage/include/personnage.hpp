#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE
#include <iostream>
#include <string>

class Personnage {      
    public:    
    Personnage(int vie = 100,std::string nom = "jack") : m_vie(100), m_nom(nom){}    
    void recevoirDegats(int degats);    
    void coupDePoing(Personnage &cible) const;  
    void sePresenter() const;
    
    protected:    
    int m_vie;    
    std::string m_nom;};

#endif