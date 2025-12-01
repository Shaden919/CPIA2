#if !defined(DEF_STATE4)
#define DEF_STATE4

#include "abstractState.hpp"

class State4 : public AbstractState
{
public:
    State4();
    ~State4();
    void action() const override;
};


#endif