#if !defined(DEF_CONCRETEOBSERVERS)
#define DEF_CONCRETEOBSERVERS

#include "observers.hpp"

class ConcreteObservers : public Observers
{
public:
    ConcreteObservers();
    ~ConcreteObservers();
    void update(Observable* obs) override;
};

#endif // DEF_CONCRETEOBSERVERS
