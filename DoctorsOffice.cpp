#include "DoctorsOffice.h"

DoctorsOffice :: DoctorsOffice()
:Building(), vaccine_capacity(100), num_vaccine_remaining(vaccine_capacity), dollar_cost_per_vaccine(5)
{
    GameObject :: display_code = 'D';
    GameObject :: state = VACCINE_AVAILABLE;
    cout << "DoctorsOffice default constructed" << endl;
} 

DoctorsOffice :: DoctorsOffice(int in_id, double vaccine_cost, unsigned int vaccine_cap, Point2D in_loc)
:Building('D',in_id,in_loc), vaccine_capacity(vaccine_cap), num_vaccine_remaining(vaccine_capacity), dollar_cost_per_vaccine(vaccine_cost)
{
    GameObject :: state = VACCINE_AVAILABLE;
    cout << "DoctorsOffice constructed" << endl;
}

DoctorsOffice :: ~DoctorsOffice()
{
    cout << "DoctorsOffice Destructed" << endl;
}

bool DoctorsOffice :: HasVaccine()
{
    if(num_vaccine_remaining > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

unsigned int DoctorsOffice :: GetNumVaccineRemaining()
{
    return num_vaccine_remaining;
}

bool DoctorsOffice :: CanAffordVaccine(unsigned int vaccine, double budget)
{
    if (budget >= (vaccine*dollar_cost_per_vaccine))
    {
        return true;
    }

    else
    {
        return false;
    }
}

double DoctorsOffice :: GetDollarCost(unsigned int vaccine)
{
    int cost = vaccine*dollar_cost_per_vaccine;
    return cost;
}

unsigned int DoctorsOffice :: DistributeVaccine(unsigned int vaccine_needed)
{
    if (num_vaccine_remaining >= vaccine_needed)
    {
        num_vaccine_remaining -= vaccine_needed;
        return vaccine_needed;
    }
    else
    {
        unsigned int vaccine_returned = num_vaccine_remaining;
        num_vaccine_remaining = 0;
        return vaccine_returned;
    }
}

bool DoctorsOffice :: Update()
{
    if(num_vaccine_remaining == 0 && (GameObject:: state != NO_VACCINE_AVAILABLE))
    {
        GameObject :: state = NO_VACCINE_AVAILABLE;
        GameObject :: display_code = 'd';
        cout << "DoctorsOffice " << id_num << " has ran out of vaccine." << endl;
        return true;
    }
    else
    {
        return false;
    }
}

void DoctorsOffice :: ShowStatus()
{
    cout << "DoctorsOffice Status: " << endl;
    Building :: ShowStatus();
    cout << "Dollars per vaccine: " << dollar_cost_per_vaccine << endl;
    cout << "has " << num_vaccine_remaining << " vaccine(s) remaining" << endl;
}



