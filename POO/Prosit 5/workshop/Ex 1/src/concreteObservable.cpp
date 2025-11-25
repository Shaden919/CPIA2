#include "concreteObservable.hpp"


ConcreteObservable::ConcreteObservable() {}
ConcreteObservable::~ConcreteObservable() {}

void ConcreteObservable::setState(int x) {
    this->state = x;
    this->notify();
}
int ConcreteObservable::getState() const {
    return state;
}