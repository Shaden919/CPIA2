#if !defined(DEF_ANGRY)
#define DEF_ANGRY

#include "avatarState.hpp"

class Angry : public AvatarState
{
public:
    Angry() {};
    ~Angry();
    void action() const override;
    AvatarState* next() const override;
};


#endif // DEF_ANGRY