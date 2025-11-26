#if !defined(DEF_GLAD)
#define DEF_GLAD

#include "avatarState.hpp"

class Glad : public AvatarState
{
public:
    Glad() {};
    ~Glad();
    void action() const override;
    AvatarState* next() const override;
};


#endif // DEF_GLAD
