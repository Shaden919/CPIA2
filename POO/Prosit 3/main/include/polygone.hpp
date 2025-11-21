#if !defined(DEF_POLYGONE)
#define DEF_POLYGONE

#include "point.hpp"

class Polygone
{
protected:
    Point* origine;
public:
    virtual ~Polygone() = 0;
    void setOrigine(Point* origine);
    Point getOrigine() const;
    virtual double aire() const = 0;
    virtual double perimeter() const = 0;
    virtual void afficheInfo() const = 0;
};


#endif // DEF_POLYGONE
