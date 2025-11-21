#if !defined(DEF_VOITURE)
#define DEF_VOITURE

#include "../include/vehicule.hpp"

class Voiture : public Vehicule
{
public:
    Voiture(int vitesseMax = 100,int acceleration = 3);
    ~Voiture();
    void setVitesseMax(int vitesseMax) override;
    void setAcceleration(int acceleration) override;
    void affiche() const override;
};

#endif // DEF_VOITURE
