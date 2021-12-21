#ifndef VIRUS_H
#define VIRUS_H

#include <string>
#include "GameObject.h"
#include "Point2D.h"

class Student;



class Virus : public GameObject
{
    protected:
    double virulence;
    double resistance;
    bool variant;
    double energy;
    bool is_in_student = false;
    string name;
    Student* current_student = NULL;

    public:
    Virus(string, double, double, double,bool,int,Point2D);
    ~Virus();
    void infect(Student* s);
    bool get_variant();
    double get_virulence();
    double get_resistance();
    double get_energy();
    bool get_in_student();
    bool Update();
    void ShowStatus();
    bool IsAlive();
    bool ShouldBeVisible();
    //Function added to move Virus along with the Student
    void UpdateLocation(Point2D);
    string GetName();
    //CLears the value of student
    void ClearVirus();
    //Function wriiten for Hospital
    void KillVirus();
};

enum VirusStates
{
    IN_ENVIRONMENT = 0,
    DEAD = 1,
    IN_STUDENT = 2,
};


#endif