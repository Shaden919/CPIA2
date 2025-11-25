#if !defined(DEF_OBSERVERS)
#define DEF_OBSERVERS

class Observable;


class Observers
{
public:
    virtual ~Observers();
    virtual void update(Observable* obs) = 0;
};


#endif // DEF_OBSERVERS
