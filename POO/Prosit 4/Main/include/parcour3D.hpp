#if !defined(DEF_PARCOUR3D)
#define DEF_PARCOUR3D

#include "parcour.hpp"

class Parcour3D : public Parcour
{
public:
    Parcour3D(int nbPoint);
    ~Parcour3D();
    float calculDistance() const override;
    void message() const override;
};


#endif // DEF_PARCOUR3D