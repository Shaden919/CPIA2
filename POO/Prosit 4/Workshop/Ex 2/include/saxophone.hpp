#if !defined(DEF_SAXOPHONE)
#define DEF_SAXOPHONE

#include "instrument.hpp"

class Saxophone : public Instrument
{
public:
    Saxophone();
    ~Saxophone();
    void jouer() override;
};

#endif // DEF_SAXOPHONE