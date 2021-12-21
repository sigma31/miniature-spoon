#include "Vector2D.h"
#include "Point2D.h"
#include "GameObject.h"
#include "Building.h"
#include "ClassRoom.h"
#include "DoctorsOffice.h"
#include "Student.h"
#include "Model.h"
#include "GameCommand.h"
#include <vector>
#include <cstring>
#include <iomanip>
#include <sstream>

using namespace std;
int main()
{
    Student Bart("Bart",1,'S',2, Point2D(0,0));
    Hospital H(2,1,2,Point2D(5,5));
    Hospital* Hosp_ptr = &H; 
    Bart.GetBooster();
    Bart.GetCure();
    Bart.StartMovingToHospital(Hosp_ptr);
   do
    {
      Bart.ShowStatus();
    } while (!Bart.Update());

    Bart.GetBooster();
    Bart.ShowStatus();
    Bart.Update();
    Bart.GetCure();
    Bart.ShowStatus();
    Bart.Update();
    
}
