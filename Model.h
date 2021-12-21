#ifndef MODEL_H
#define MODEL_H

#include "GameObject.h"
#include "Student.h"
#include "Building.h"
#include "DoctorsOffice.h"
#include "ClassRoom.h"
#include "View.h"
#include "Virus.h"
#include "Input_Handling.h"
#include "Hospital.h"
#include <list>

class Model 
{
    private:
    int time;
    list <GameObject*> object_ptrs;
    list <GameObject*> active_ptrs;
    list <Student*> student_ptrs;
    list <DoctorsOffice*> office_ptrs;
    list <ClassRoom*> class_ptrs;
    list <Virus*> virus_ptrs;
    //List added for Hospital
    list <Hospital*> hospital_ptrs;

    public:
    Model();
    ~Model();
    Student* GetStudentPtr(int id);
    DoctorsOffice* GetDoctorsOfficePtr(int id);
    ClassRoom* GetClassRoomPtr(int id);
    //Function added to get Hospital pointers
    Hospital* GetHospitalPtr(int id);
    bool Update();
    void Display(View& view);
    void ShowStatus();
    //Functions for Object creation
    void NewCommand(char, int, double, double);
};
#endif