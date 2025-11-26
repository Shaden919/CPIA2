#include "happy.hpp"
#include "sad.hpp"
#include <iostream>

Happy::~Happy() {}
void Happy::action() const{
    std::cout << "je suis heureux\n";
}
AvatarState* Happy::next() const{
    AvatarState* out;
    out = new Sad;
    return out;
}