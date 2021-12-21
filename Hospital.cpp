#include "Hospital.h"

Hospital :: Hospital()
:Building(), boostershot_capacity(1), num_boostershots_remaining(1),boostershot_cost(30)
{
    GameObject :: display_code = 'H';
    state = BOOSTER_AVAILABLE;
    cout << "Default Hospital constructed" << endl;
}

Hospital :: Hospital(unsigned int booster_capacity,double booster_cost, int in_id, Point2D in_loc)
:Building('H',in_id,in_loc), boostershot_capacity(booster_capacity), num_boostershots_remaining(booster_capacity),boostershot_cost(booster_cost)
{
    state = BOOSTER_AVAILABLE;
    cout << "Hospital constructed" << endl;
}

Hospital :: ~Hospital()
{
    cout << "Hospital destructed" << endl;
}

bool Hospital :: HasBoosterShot()
{
    if (num_boostershots_remaining <= 0)
        return false;
    return true;
}

double Hospital :: GetVirusCureCost(double virus_virulence)
{
    return virus_virulence*3;
}

double Hospital :: GetBoosterShotCost()
{
    return boostershot_cost;
}

unsigned int Hospital :: DistributeBoosterShot()
{
    if(this->HasBoosterShot())
    {    
        num_boostershots_remaining--;
        return 1;
    }
    else
        return 0;
}

bool Hospital :: Update()
{
    if(num_boostershots_remaining == 0 && state != NO_BOOSTER_AVAILABLE)
    {
        state = NO_BOOSTER_AVAILABLE;
        display_code = 'h';
        cout << "Hospital " << id_num << " has run out of booster shots" << endl;
        cout << "You can still go there to cure yourself of viruses" << endl;
        return true; 
    }
    else
    {
        return false;
    }
}

void Hospital :: ShowStatus()
{
    cout << "Hospital Status: " << endl;
    Building :: ShowStatus();
    cout << "Cost per booster shot: " << this->GetBoosterShotCost() << endl;
    cout << "Booster shots remaining: " << this->num_boostershots_remaining << endl;
}