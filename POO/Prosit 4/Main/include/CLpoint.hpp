#if !defined(DEF_CLPOINT)
#define DEF_CLPOINT

class CLpoint
{
protected:
    float x,y;
public:
    CLpoint(float x = 0., float y = 0.);
    virtual ~CLpoint();
    void setX(float x);
    void setY(float y);
    float getX() const;
    float getY() const;
    virtual void setZ(float z);
    virtual float getZ() const;
    virtual void afficherCoordo() const;
};

#endif // DEF_CLPOINT
