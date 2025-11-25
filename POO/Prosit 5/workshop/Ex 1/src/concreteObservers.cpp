#include "concreteObservers.hpp"
#include "concreteObservable.hpp"
#include <iostream>

ConcreteObservers::ConcreteObservers() {}
ConcreteObservers::~ConcreteObservers() {}
void ConcreteObservers::update(Observable* obs) {
    ConcreteObservable* obs_concret = dynamic_cast<ConcreteObservable*> (obs);
    std::cout << "Mise a jour de " << obs_concret << std::endl;
    std::cout << "      -   nouveaux state : " << obs_concret->getState() << std::endl;
}