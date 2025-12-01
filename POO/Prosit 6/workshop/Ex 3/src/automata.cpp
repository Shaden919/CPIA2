#include "automata.hpp"
#include "state1.hpp"
#include "state2.hpp"
#include "state3.hpp"
#include "state4.hpp"

Automata::~Automata() {
    for (auto const& [key, val] : stateObjects) {
        delete val; // Supprime l'objet alloué avec new
    }
    stateObjects.clear(); // Vide la map
}


void Automata::action() const{
    auto it = delta.find(currentState);
    it->second->action();
}
void Automata::transition() {}
void Automata::initAutomata() {
    map<StateID,StateID> tmp{{I1,I2},{I2,I3},{I3,I4},{I4,I0}};
    state = tmp;
    delta[I1] = new state1();
    delta[I2] = new state2();
    delta[I3] = new state3();
    delta[I4] = new state4();
    delta[I0] = nullptr; // L'état final n'a pas d'action

    currentState = nullptr;
}