#if !defined(DEF_SAD)
#define DEF_SAD

#include "avatarState.hpp"

class Sad : public AvatarState
{
public:
    Sad() {};
    ~Sad();
    void action() const override;
    AvatarState* next() const override;
};


#endif // DEF_SAD