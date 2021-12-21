#ifndef BUILDING_H
#define BUILDING_H
#include <iostream>
#include "GameObject.h"
#include "Point2D.h"

class Building : public GameObject
{
    private:
    unsigned int student_count = 0;

    public:
    Building(); //Default Constructor
    Building(char, int, Point2D); // Parameter Constructor
    ~Building(); 
    //Public Member Functions
    void AddOneStudent(); 
    void RemoveOneStudent();
    void ShowStatus();
    bool ShouldBeVisible();
};
#endif
