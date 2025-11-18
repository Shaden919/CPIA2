#include "vehicule.hpp"
#include "bus.hpp"
#include "schoolBus.hpp"
#include <iostream>

int main() {
    Bus bus1(45,210,160000);
    Bus bus2(36,230,460000);
    Bus bus3(80,200,10000);
    Bus list[3];
    list[0] = bus1;
    list[1] = bus2;
    list[2] = bus3;
    std::cout << Bus::countBigBus(list,3) << "\n"; 
    return 0;
}