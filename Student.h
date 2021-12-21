#ifndef STUDENT_H
#define STUDENT_H
#include "GameObject.h"
#include "DoctorsOffice.h"
#include "Point2D.h"
#include "Vector2D.h"
#include "ClassRoom.h"
#include "Building.h"
#include "Model.h"
#include "math.h"
#include "cstdlib"
#include "time.h"
#include "Virus.h"
//For Hospital
#include "Hospital.h"


class Student : public GameObject
{
    private:
    double speed;
    bool is_at_doctor = false, is_in_class = false;
    unsigned int antibodies = 20, credits = 0, assignments_to_buy = 0, vaccines_to_buy = 0, boosters_to_buy;
    double dollars = 0;
    string name;
    DoctorsOffice* current_office = NULL;
    ClassRoom* current_class = NULL;
    Point2D destination;
    Vector2D delta;
    Virus* current_virus = NULL;
    Hospital* current_hospital = NULL;

    protected:
    bool UpdateLocation();
    void SetupDestination(Point2D);

    public:
    Student(); // Default Constructor
    Student(char);
    Student(string, int, char, unsigned int, Point2D);
    virtual ~Student();
    void StartMoving(Point2D);
    void StartMovingToClass(ClassRoom* classr);
    void StartMovingToDoctor(DoctorsOffice* office);
    void StartLearning(unsigned int);
    void StartRecoveringAntibodies(unsigned int);
    void Stop();
    bool IsInfected();
    bool ShouldBeVisible();
    void ShowStatus();
    bool Update();
    string GetName();
    //Function to check if student is within infection range of Virus
    void WithinRange(Virus*);
    //Function to check if student has a Virus
    bool HasVirus();
    //Functions for Hospital
    void StartMovingToHospital(Hospital* hospital);
    void GetBooster();
    void GetCure();
};




enum StudentStates
{
    STOPPED = 0,
    MOVING = 1,
    INFECTED = 2,
    AT_DOCTORS = 3,
    IN_CLASS = 4,
    MOVING_TO_DOCTOR = 5,
    MOVING_TO_CLASS = 6,
    STUDYING_IN_CLASS = 7,
    RECOVERING_ANTIBODIES = 8,
    //States for Hospital
    MOVING_TO_HOSPITAL = 9,
    AT_HOSPITAL = 10,
    BOOSTING_ANTIBODIES = 11,
    CURING_VIRUS = 12,
};

double GetRandomAmountOfDollars();
#endif