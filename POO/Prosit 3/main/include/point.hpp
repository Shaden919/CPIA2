#include "vector.hpp"

#if !defined(DEF_POINT)
#define DEF_POINT

class Point
{
private:
    float x;
    float y;
public:
    Point(float x = 0, float y = 0);
    ~Point();
    void setX(float x);
    void setY(float y);
    void print() const;
    float getX() const;
    float getY() const;
    Vector minus(Point point) const;
    Point add(Vector vector) const;
};


#endif // DEF_POINT
