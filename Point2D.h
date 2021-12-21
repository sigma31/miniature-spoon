#ifndef POINT2D_H
#define POINT2D_H
#include <iostream>
#include "math.h"
#include "Vector2D.h"
using namespace std;

class Point2D
{
    public:
        double x, y;

    public:
        Point2D(); // Default constructor
        Point2D(double in_x, double in_y); // Parameter Constructor
};
//Non Member Function
double GetDistanceBetween(Point2D, Point2D);
//Non Member Overloaded Operators
ostream& operator << (ostream&, const Point2D&);
Point2D operator + (Point2D, Vector2D);
Vector2D operator - (Point2D, Point2D);

#endif