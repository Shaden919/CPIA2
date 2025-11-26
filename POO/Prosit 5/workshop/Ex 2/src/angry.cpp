#include "angry.hpp"
#include "grumpy.hpp"
#include <iostream>

Angry::~Angry() {}
void Angry::action() const{
    std::cout <<"je suis en colere\n";
}
AvatarState* Angry::next() const {
    AvatarState* out;
    out = new Grumpy;
    return out;
}