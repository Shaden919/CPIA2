#if !defined(DEF_STATION)
#define DEF_STATION

#include "moto.hpp"

class Station
{
private:
    Moto** parc;
    int place;
public:
    Station(int place);
    ~Station();
    void lavage() const;
    void add(int place,Moto* moto);
    void supr(int place);
};


#endif // DEF_STATION
