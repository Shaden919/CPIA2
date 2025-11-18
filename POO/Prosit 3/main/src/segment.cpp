#include <iostream>
#include <segment.hpp>
using namespace std;

Segment::Segment(Point origin, Vector direction){
    this->origin = origin;
    this->direction = direction;
}
Segment::~Segment(){}
float Segment::length() const{
    return this->direction.norm();
}
void Segment::setOrigin(Point point){
    this->origin = point;
}
Point Segment::getOrigin() const{
    return this->origin;
}
void Segment::setDirection(Vector vector){
    this->direction = vector;
}
Vector Segment::getDirection() const{
    return this->direction;
}
IntersectionStatus Segment::intersect(Segment segment, Point point) const{
    Point oa = getOrigin(), ob = segment.getOrigin();
    Vector da = getDirection(), db = segment.getDirection();
    Vector dc = ob.minus(oa);

    IntersectionStatus status;
    float det = da.cross(db);
    if (det != 0.0) {
        float u, v;

        u = dc.cross(db) / det;
        v = dc.cross(da) / det;
        if ((u >= 0.0 && u <= 1.0) && (v >= 0.0 && v <= 1.0)) {
            Vector tmp = da.scalar( u);
            point = oa.add(tmp);
            status = POINT;
        } else {
            status = NON_INTERSECTING;
        }
    } else {
        float st = dc.cross(da);
        if (det == 0.0 && st == 0.0) { // check for collinearity
            float pj, d1, d2;

            pj = da.dot(da);
            d1 = dc.dot(da) / pj;
            d2 = d1 + db.dot(da) / pj;

            if (d1 >= 0.0 && d1 <= 1.0) {
                point = ob;
                status = COLINEAR_INTERSECTING;
            } else if (d2 >= 0.0 && d2 <= 1.0) {
                Point tmp_ob_db = ob.add(db);
                point = tmp_ob_db;
                status = COLINEAR_INTERSECTING;
            } else {
                status = COLINEAR_NON_INTERSECTING;
            }
        } else if (det == 0.0 && st != 0.0) {
            status = PARALLEL_NON_INTERSECTING;
        }
    }

    return status;
}