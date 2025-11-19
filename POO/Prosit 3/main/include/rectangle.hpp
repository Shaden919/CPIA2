#if !defined(DEF_RECTANGLE)
#define DEF_RECTANGLE

#include "polygone.hpp"

class Rectangle : public Polygone
{
private:
    double longueur,largeur;
public:
    Rectangle(Point origine,double longueur,double largeur);
    ~Rectangle();
    double aire() override;
    double perimeter() override;
    void afficheInfo() override;
};

#endif // DEF_RECTANGLE
