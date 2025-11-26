#include "grumpy.hpp"
#include "glad.hpp"
#include <iostream>

Grumpy::~Grumpy() {}
void Grumpy::action() const{
    std::cout << "je suis grincheux\n";
}
AvatarState* Grumpy::next() const{
    AvatarState* out;
    out = new Glad;
    return out;
}