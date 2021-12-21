#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <iostream>
using namespace std;

class Vector2D
{
    public:
        double x, y;

    public:
        Vector2D(); //Default Constructor
        Vector2D(double in_x, double in_y); // Parameter Constructor
};

 //Non Member Overloaded Operators
Vector2D operator * (Vector2D, double);
Vector2D operator / (Vector2D, double);
ostream& operator << (ostream&, Vector2D);

#endif