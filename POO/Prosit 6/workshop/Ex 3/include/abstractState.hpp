#if !defined(DEF_ABSTRACTSTATE)
#define DEF_ABSTRACTSTATE

#include <iostream>
using namespace std;

enum StateID {
    I1,
    I2,
    I3,
    I4,
    I0
};

class AbstractState
{
public:
    virtual ~AbstractState();
    virtual void action() const = 0;
};
#endif // DEF_ABSTRACTSTATE
