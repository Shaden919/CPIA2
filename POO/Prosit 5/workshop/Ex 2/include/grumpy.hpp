#if !defined(DEF_GRUMPY)
#define DEF_GRUMPY

#include "avatarState.hpp"

class Grumpy : public AvatarState
{
public:
    Grumpy() {};
    ~Grumpy();
    void action() const override;
    AvatarState* next() const override;
};


#endif // DEF_GRUMPY