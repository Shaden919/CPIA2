#if !defined(DEF_HAPPY)
#define DEF_HAPPY

#include "avatarState.hpp"

class Happy : public AvatarState
{
public:
    Happy() {};
    ~Happy();
    void action() const override;
    AvatarState* next() const override;
};


#endif // DEF_HAPPY