#include "sad.hpp"
#include "angry.hpp"
#include <iostream>

Sad::~Sad() {}
void Sad::action() const{
    std::cout << "je suis triste\n";
}
AvatarState* Sad::next() const{
    AvatarState* out;
    out = new Angry;
    return out;
}