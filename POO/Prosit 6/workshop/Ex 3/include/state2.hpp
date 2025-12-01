#if !defined(DEF_STATE2)
#define DEF_STATE2

#include "abstractState.hpp"

class State2 : public AbstractState
{
public:
    State2();
    ~State2();
    void action() const override;
};


#endif