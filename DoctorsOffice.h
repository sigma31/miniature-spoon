#ifndef DOCTORSOFFICE_H
#define DOCTORSOFFICE_H
#include <iostream>
#include "Building.h"
#include "Point2D.h"

class DoctorsOffice : public Building
{
    private:
    unsigned int vaccine_capacity;
    unsigned int num_vaccine_remaining;
    double dollar_cost_per_vaccine;

    public:
    DoctorsOffice(); //Default Constructor
    DoctorsOffice(int,double,unsigned int,Point2D); // Parameter Constructor
    ~DoctorsOffice();
    // Public Member Functions
    bool HasVaccine();
    unsigned int GetNumVaccineRemaining();
    bool CanAffordVaccine(unsigned int, double);
    double GetDollarCost(unsigned int);
    unsigned int DistributeVaccine(unsigned int);
    bool Update();
    void ShowStatus();
};

enum DoctorsOfficeStates {VACCINE_AVAILABLE = 0, NO_VACCINE_AVAILABLE = 1};

#endif