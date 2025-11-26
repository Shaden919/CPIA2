#include "glad.hpp"
#include "happy.hpp"
#include <iostream>

Glad::~Glad() {}
void Glad::action() const{
    std::cout << "je suis content\n";
}
AvatarState* Glad::next() const{
    AvatarState* out;
    out = new Happy;
    return out;
}