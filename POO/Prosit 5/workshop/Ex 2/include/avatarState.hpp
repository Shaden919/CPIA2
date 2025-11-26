#if !defined(DEF_AVATARSTATE)
#define DEF_AVATARSTATE

class AvatarState
{
public:
    virtual ~AvatarState();
    virtual void action() const = 0;
    virtual AvatarState* next() const = 0;
};


#endif // DEF_AVATARSTATE
