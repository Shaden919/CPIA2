#if !defined(DEF_CARRE)
#define DEF_CARRE

#include "polygone.hpp"

class Carre : public Polygone
{
private:
    double cote;
    Point* fin;
public:
    Carre(Point* origine,Point* fin);
    ~Carre();
    double aire()  const override;
    double perimeter() const override;
    void afficheInfo() const override;
};

#endif // DEF_CARRE
