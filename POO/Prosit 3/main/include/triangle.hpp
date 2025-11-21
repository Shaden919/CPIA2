#if !defined(DEF_TRIANGLE)
#define DEF_TRIANGLE

#include "polygone.hpp"

class Triangle : public Polygone
{
private:
    Vector aileDroite, aileGauche;
public:
    Triangle(Point* origine,Vector aileDroite,Vector aileGauche);
    ~Triangle();
    void setAileDroite(Vector aileDrtoie);
    void setAileGauche(Vector aileGauche);
    Vector getAileDroite() const;
    Vector getAilegauche() const;
    double aire() const;
    double perimeter() const;
    void afficheInfo() const;
};


#endif // DEF_TRIANGLE
