#include "Virus.h"

Virus :: Virus(string name, double virulence, double resistance, double energy, bool variant, int id, Point2D in_loc)
:GameObject(in_loc,id,'V'), name(name), virulence(virulence), resistance(resistance), variant(variant), energy(energy)
{
    state = IN_ENVIRONMENT;
    cout << "Virus constructed" << endl;    
}

void Virus :: infect(Student* s)
{
    this->current_student = s;
    state = IN_STUDENT;
    is_in_student = true;
}

bool Virus :: get_variant()
{
    return variant;
}

double Virus :: get_virulence()
{
    return virulence;
}

double Virus :: get_resistance()
{
    return resistance;
}

double Virus :: get_energy()
{
    return energy;
}

bool Virus :: get_in_student()
{
    return is_in_student;
}



bool Virus :: Update()
{
    if(!this->IsAlive())
        {
            state = DEAD;
            return false;
        }
    else if(state == IN_ENVIRONMENT)
        {
            return false;
        }
    else if(state == IN_STUDENT)
        {
            energy -= 1;
            return false;
        }
    return false;
}

void Virus :: ShowStatus()
{
    cout << "Virus " << name << " status: " << endl;
    GameObject:: ShowStatus();
    cout << "Energy: " << get_energy() << endl;
    switch(state)
    {
        case IN_ENVIRONMENT: cout << "The virus " << name << " is looking to make someone sick" << endl;
            break;
        case DEAD: cout << "The virus " << name << " is dead" << endl;
            break;
        case IN_STUDENT: cout << "The virus " << name << " has infected a student" << endl;
            break;
    }
}

bool Virus :: IsAlive()
{
    if(energy <= 0)
    {    
        state = DEAD;
        return false;
    }
    return true;
}

bool Virus :: ShouldBeVisible()
{
    if(IsAlive())
        return true;
    return false;
}

void Virus :: UpdateLocation(Point2D dest)
{
    location = dest;
    energy -=1;
}

string Virus :: GetName()
{
    return name;
}

//Clears the value of current_student
void Virus :: ClearVirus()
{
    current_student = NULL;
    is_in_student = false;
    state = IN_ENVIRONMENT;
}

Virus :: ~Virus()
{
    cout << "Virus destructed" << endl;
}

//Function written for Hospital
void Virus :: KillVirus()
{
    energy = 0;
    state = DEAD;
}
