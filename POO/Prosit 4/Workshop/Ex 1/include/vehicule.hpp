#if !defined(DEF_VEHICULE)
#define DEF_VEHICULE

class Vehicule
{
protected:
    int vitesse,vitesseMax,acceleration;
public:
    virtual ~Vehicule();
    void setVitesse(int vitesse);
    virtual void setVitesseMax(int vitesseMax) = 0;
    virtual void setAcceleration(int acceleration) = 0;
    virtual void affiche() const = 0;
    int getVitesse() const;
    int getVitesseMax() const;
    int getAcceleration() const;
    void accelerer();
}; 


#endif // DEF_VEHICULE
