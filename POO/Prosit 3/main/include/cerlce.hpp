#if !defined(DEF_CERCLE)
#define DEF_CERCLE

#include "polygone.hpp"

class Cerlce : public Polygone
{
private:
    double rayon;
public:
    Cerlce(Point *origine,double rayon);
    ~Cerlce();
    void setOrigine(Point* origine) override;
    Point getOrigine() const override;
    void setRayon(double rayon);
    double getRayon() const;
    double aire() const override;
    double perimeter() const override;
    void afficheInfo() const override;
};


#endif // DEF_CERCLE
