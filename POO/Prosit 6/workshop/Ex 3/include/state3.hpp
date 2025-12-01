#if !defined(DEF_STATE3)
#define DEF_STATE3

#include "abstractState.hpp"

class State3 : public AbstractState
{
public:
    State3();
    ~State3();
    void action() const override;
};


#endif