#include "point.hpp"
#include "vector.hpp"

typedef enum {
    POINT,
    COLINEAR_INTERSECTING,
    COLINEAR_NON_INTERSECTING,
    PARALLEL_NON_INTERSECTING,
    NON_INTERSECTING
} IntersectionStatus;


#if !defined(DEF_SEGMENT)
#define DEF_SEGMENT

class Segment
{
private:
    Point origin;
    Vector direction;
public:
    Segment(Point origin, Vector direction);
    ~Segment();
    float length() const;
    void setOrigin(Point point);
    void setDirection(Vector vector);
    Point getOrigin() const;
    Vector getDirection() const;
    IntersectionStatus intersect(Segment segment, Point point) const;
};


#endif // DEF_SEGMENT
