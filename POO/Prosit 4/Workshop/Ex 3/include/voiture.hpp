#if !defined(DEF_VOITURE)
#define DEF_VOITURE

#include "moto.hpp"

class Voiture : public Moto
{
public:
    Voiture();
    ~Voiture();
    void lave() const override;
};


#endif // DEF_VOITURE
