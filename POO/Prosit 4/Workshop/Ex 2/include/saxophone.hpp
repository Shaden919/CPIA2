#if !defined(DEF_SAXOPHONE)
#define DEF_SAXOPHONE

#include "instrument.hpp"

class Saxosphone : public Instrument
{
public:
    Saxosphone(/* args */);
    ~Saxosphone();
    void jouer() override;
};

#endif // DEF_SAXOPHONE