#include "observable.hpp"
#include "observers.hpp"
#include "concreteObservable.hpp"
#include "concreteObservers.hpp"


int main() {
    ConcreteObservable* cailloux;
    cailloux = new ConcreteObservable;

    Observers* louis;
    Observers* antonin;
    Observers* gabriel;

    louis = new ConcreteObservers;
    antonin = new ConcreteObservers;
    gabriel = new ConcreteObservers;

    cailloux->subscribe(louis);
    cailloux->subscribe(antonin);

    cailloux->setState(20);

    delete cailloux;

    delete louis;
    delete antonin;
    delete gabriel;

    return 0;
}