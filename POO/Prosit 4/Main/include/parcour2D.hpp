#if !defined(DEF_PARCOUR2D)
#define DEF_PARCOUR2D

#include "parcour.hpp"

class Parcour2D : public Parcour
{
public:
    Parcour2D(int nbPoint);
    ~Parcour2D();
    float calculDistance() const override;
    void message() const override;
};


#endif // DEF_PARCOUR2D
