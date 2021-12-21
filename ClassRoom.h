#ifndef CLASSROOM_H
#define CLASSROOM_H
#include "Building.h"
#include "Point2D.h"

class ClassRoom : public Building
{
    private:
    unsigned int num_assignments_remaining;
    unsigned int max_number_of_assignments;
    unsigned int antibody_cost_per_assignment;
    double dollar_cost_per_assignment;
    unsigned int credits_per_assignment;

    public:
    ClassRoom(); // Default Constructor
    ClassRoom(unsigned int, unsigned int, double, unsigned int, int, Point2D); // Parameter Constructor
    ~ClassRoom();

    //Public Member Functions
    double GetDollarCost(unsigned int);
    unsigned int GetAntibodyCost(unsigned int);
    unsigned int GetNumAssignmentsRemaining();
    unsigned int GetCreditsPerAssignment();
    bool IsAbleToLearn(unsigned int, double, unsigned int);
    unsigned int TrainStudents(unsigned int);
    bool Update();
    bool passed();
    void ShowStatus();
};

enum ClassRoomStates
{
    NOT_PASSED = 0,
    PASSED = 1
};

#endif