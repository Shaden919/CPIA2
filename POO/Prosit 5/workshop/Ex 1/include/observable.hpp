#if !defined(DEF_OBSERVABLE)
#define DEF_OBSERVABLE

#include "observers.hpp"
#include <vector>
using namespace std;

class Observable
{
protected:
    vector<Observers*> follower;
    void notify();
public:
    virtual ~Observable();
    int subscribe(Observers* obs);
    int unsuscribe(Observers* obs);
};

#endif // DEF_OBSERVABLE
