#if !defined(DEF_SCHOOLBUS)
#define DEF_SCHOOLBUS

#include "bus.hpp"
#include "string"
using namespace std;

class SchoolBus : public Bus
{
private:
    string nameSchool;
public:
    SchoolBus(string nameSchool,int seat_capacity = 10,int max_speed = 240,int kilometrage = 0) : Bus(seat_capacity,max_speed,kilometrage),nameSchool(nameSchool) {}
    ~SchoolBus();
    void setNameSchool(string nameSchool);
    string getNameSchool() const;
};



#endif // DEF_SCHOOLBUS
