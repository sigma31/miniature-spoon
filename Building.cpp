#include "Building.h"

Building :: Building()
:GameObject('B')
{
    cout << "Building default constructed" << endl;
}

Building :: Building(char in_code, int in_id, Point2D in_loc)
:GameObject(in_loc,in_id,in_code)
{
    cout << "Building constructed" << endl;
}

Building :: ~Building()
{
    cout << "Bulding destructed" << endl;
}

void Building :: AddOneStudent()
{
    student_count++;
}

void Building :: RemoveOneStudent()
{
    student_count--;
}

void Building::ShowStatus()
{
    GameObject:: ShowStatus();
    if(student_count > 1)
    {
        cout << student_count << " students is in this building" << endl;
    }
    else
    {
        cout << student_count << " students are in this building" << endl;
    }
}

bool Building :: ShouldBeVisible()
{
    return true;
}





