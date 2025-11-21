#if !defined(DEF_PARCOUR)
#define DEF_PARCOUR

#include "CLpoint.hpp"
#include <vector>
using namespace std;

class Parcour
{
protected:
    vector<CLpoint*> tab;
public:
    Parcour(int nbPoint);
    virtual ~Parcour();
    void print() const;
    void ajouterPoint(CLpoint* point);
    virtual float calculDistance() const = 0;
    virtual void message() const = 0;
};

#endif // DEF_PARCOUR
