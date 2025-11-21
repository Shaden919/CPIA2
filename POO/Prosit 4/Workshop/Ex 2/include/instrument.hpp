#if !defined(DEF_INSTRUMENT)
#define DEF_INSTRUMENT

class Instrument
{
public:
    virtual ~Instrument();
    virtual void jouer() = 0;
};


#endif // DEF_INSTRUMENT
