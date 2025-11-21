#if !defined(DEF_VOITURESPORT)
#define DEF_VOITURESPORT

#include "../include/vehicule.hpp"

class VoitureSport : public Vehicule
{
public:
    VoitureSport(int vitesseMax = 200, int acceleration = 8);
    ~VoitureSport();
    void setVitesseMax(int vitesseMax) override;
    void setAcceleration(int acceleration) override;
    void affiche() const override;
};

#endif // DEF_VOITURESPORT
