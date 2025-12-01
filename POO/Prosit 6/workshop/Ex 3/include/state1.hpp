#if !defined(DEF_STATE1)
#define DEF_STATE1

#include "abstractState.hpp"

class State1 : public AbstractState
{
public:
    State1();
    ~State1();
    void action() const override;
};


#endif
