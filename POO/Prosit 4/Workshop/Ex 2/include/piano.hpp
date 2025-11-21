#if !defined(DEF_PIANO)
#define DEF_PIANO

#include "instrument.hpp"

class Piano : public Instrument
{
public:
    Piano();
    ~Piano();
    void jouer() override;
};


#endif // DEF_PIANO
