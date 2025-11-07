#if !defined(DEF_CLOBJET)
#define DEF_CLOBJET

class CLobjet
{
private:
    float* m_masse;
    float* m_vitesse;
    float* m_energieC;
public:
    CLobjet(float masse, float vitesse);
    ~CLobjet();
    float masse(float masse);
    float vitesse(float vitesse);
    float energieC() const;
    void calculer();
};


#endif // DEF_CLOBJET
