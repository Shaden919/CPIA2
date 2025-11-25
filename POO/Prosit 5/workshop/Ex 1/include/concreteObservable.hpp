#if !defined(DEF_CONCRETEOBSERVABLE)
#define DEF_CONCRETEOBSERVABLE

#include "observable.hpp"

class ConcreteObservable : public Observable
{
private : 
    int state;
public:
    ConcreteObservable();
    ~ConcreteObservable();
    void setState(int x);
    int getState() const;
};


#endif // DEF_CONCRETEOBSERVABLE
