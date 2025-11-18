#if !defined(DEF_BUS)
#define DEF_BUS

#include "vehicule.hpp"

class Bus : public Vehicule
{
protected:
    int seat_capacity;
public:
    Bus(int seat_capacity = 10,int max_speed = 240,int kilometrage = 0) : Vehicule(max_speed,kilometrage),seat_capacity(seat_capacity) {}
    ~Bus() {}
    void setSeat_capacity(int seat_capacity);
    int getSeat_capacity() const;
    void getInfo() const;

    static int countBigBus(Bus list[],int taille);
};


#endif // DEF_BUS
