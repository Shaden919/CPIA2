#include "avatar.hpp"

Avatar::Avatar(AvatarState* state) {
    this->state = state;
}
Avatar::~Avatar() {}
void Avatar::run() {
    state->action();
    AvatarState* tmpState = state->next();
    delete state;
    state = tmpState;
}