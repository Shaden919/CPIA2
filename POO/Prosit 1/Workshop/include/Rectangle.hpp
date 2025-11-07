#if !defined(DEf_RECTANGLE)
#define DEf_RECTANGLE

class Rectangle
{
private:
    double m_x;
    double m_y;
    double m_width;
    double m_height;
public:
    Rectangle();
    Rectangle(double x, double y, double width, double height);
    ~Rectangle();
    void setPosition(double x, double y);
    void setWidth(double width);
    void setHeight(double height);
    void printPosition() const;
    double perimeter() const;
    double area() const;
};

#endif // DEf_RECTANGLE
