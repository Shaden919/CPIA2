#if !defined(DEF_RECTANGLE)
#define DEF_RECTANGLE

#include "polygone.hpp"

class Rectangle : public Polygone
{
protected:
    Vector longueur,largeur;
public:
    Rectangle(Point* origine,Vector longueur,Vector largeur);
    ~Rectangle();
    double aire() const override;
    double perimeter() const override;
    void afficheInfo() const override;
};

#endif // DEF_RECTANGLE
