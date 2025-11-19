#if !defined(DEF_POLUYGONE)
#define DEF_POLUYGONE

#include "point.hpp"

class Polygone
{
protected:
    Point* origine;
public:
    virtual ~Polygone() = 0;
    virtual void setOrigine(Point* origine) = 0;
    virtual Point getOrigine() const = 0;
    virtual double aire() const = 0;
    virtual double perimeter() const = 0;
    virtual void afficheInfo() const = 0;
};


#endif // DEF_POLUYGONE
