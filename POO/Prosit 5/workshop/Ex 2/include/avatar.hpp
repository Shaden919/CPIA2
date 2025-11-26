#if !defined(DEF_AVATAR)
#define DEF_AVATAR

#include "avatarState.hpp"

class Avatar
{
private:
    AvatarState* state;
public:
    Avatar(AvatarState* state);
    ~Avatar();
    void run();
};

#endif // DEF_AVATAR
