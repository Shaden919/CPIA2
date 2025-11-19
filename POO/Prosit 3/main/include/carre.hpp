#if !defined(DEF_CARRE)
#define DEF_CARRE

#include "rectangle.hpp"

class Carre : public Rectangle
{
private:
public:
    Carre(Point* origine,Vector cote);
    ~Carre();
    void afficheInfo() const;
};

#endif // DEF_CARRE
