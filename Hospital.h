#ifndef HOSPITAL_H
#define HOSPITAL_H
#include "Building.h"
#include "Point2D.h"
#include <iostream>


class Hospital : public Building
{
    private:
    unsigned int num_boostershots_remaining;
    unsigned int boostershot_capacity;
    double boostershot_cost;
    public:
    Hospital(); //Default Constructor
    Hospital(unsigned int,double, int, Point2D);//Parameter Constructor
    ~Hospital(); //Destructor

    //Public Member Function
    bool HasBoosterShot();
    double GetVirusCureCost(double);
    double GetBoosterShotCost();
    unsigned int DistributeBoosterShot();
    bool Update();
    void ShowStatus();

};

enum HospitalStates{ BOOSTER_AVAILABLE = 0, NO_BOOSTER_AVAILABLE = 1};
#endif