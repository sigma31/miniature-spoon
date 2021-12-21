#include "Point2D.h"

Point2D :: Point2D()
:x(0.0), y(0.0)
{

}

Point2D :: Point2D(double in_x, double in_y)
: x(in_x), y(in_y)
{
    
}

ostream& operator << (ostream& out, const Point2D& p1)
{
    out << "(" << p1.x << "," << p1.y << ")";
    return out; 
}

Point2D operator + (Point2D p1, Vector2D v1)
{
    Point2D p2;
    p2.x = p1.x + v1.x;
    p2.y = p1.y + v1.y;
    return p2;
}

Vector2D operator - (Point2D p1, Point2D p2)
{
    Vector2D v1;
    v1.x = p1.x - p2.x;
    v1.y = p1.y - p2.y;
    return v1;
}

//Used distance formula
double GetDistanceBetween(Point2D p1, Point2D p2)
{
    double x_diff = fabs(p1.x - p2.x);
    double y_diff = fabs(p1.y - p2.y);

    return sqrt(pow(fabs(x_diff),2)+pow(fabs(y_diff),2));
}