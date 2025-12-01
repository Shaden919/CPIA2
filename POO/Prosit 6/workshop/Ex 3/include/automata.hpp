#if !defined(DEF_AUTOMATA)
#define DEF_AUTOMATA

#include <map>
#include "abstractState.hpp"
using namespace std;


class Automata
{
private:
    map<StateID,StateID> state;
    map<StateID,AbstractState*> delta;
    StateID currentState;
public:
    Automata();
    ~Automata();
    void initAutomata();
    void transition();
    void action() const;
    void run() const;
};


#endif // DEF_AUTOMATA
