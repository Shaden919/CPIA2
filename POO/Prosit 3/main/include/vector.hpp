#if !defined(DEF_VECTOR)
#define DEF_VECTOR

class Vector
{
private:
    float x;
    float y;
public:
    Vector(float x = 0, float y = 0);
    ~Vector();
    void setX(float x);
    void setY(float y);
    float getX() const;
    float getY() const;
    float dot(Vector vector) const;
    double norm() const;
    float cross(Vector vector) const;
    Vector scalar(float scalar) const;
    Vector negate() const;
};


#endif // DEF_VECTOR
