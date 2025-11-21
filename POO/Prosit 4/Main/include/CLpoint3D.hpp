#if !defined(DEF_CLPOINT3D)
#define DEF_CLPOINT3D

#include "CLpoint.hpp"

class CLpoint3D : public CLpoint
{
private:
    float z;
public:
    CLpoint3D(float x = 0.,float y = 0., float z = 0.);
    ~CLpoint3D();
    void setZ(float z) override;
    float getZ() const override;
    void afficherCoordo() const override;
};


#endif // DEF_CLPOINT3D
