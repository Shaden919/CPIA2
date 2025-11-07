#if !defined(DEF_CIRCLE)
#define DEF_CIRCLE

class Circle
{
private:
    double m_x;
    double m_y;
    double m_radius;
public:
    Circle();
    Circle(double x, double y, double radius);
    ~Circle();
    void setPosition(double x, double y);
    void setRadius(double radius);
    void printPosition() const;
    double perimeter() const;
    double area() const;
};

#endif // DEF_CIRCLE
