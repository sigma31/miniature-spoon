#include "Student.h"

Student :: Student()
: GameObject('S'),speed(5)
{
    cout << "Student default constructed" << endl;
}

Student :: Student(char in_code)
:GameObject(in_code),speed(5)
{
    state = STOPPED;
    cout << "Student constructed" << endl;
}

Student :: Student(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc)
: name(in_name), speed(in_speed), GameObject(in_code)
{
    id_num = in_id;
    location = in_loc;
    state = STOPPED;
    cout << "Student constructed" << endl;

}

Student :: ~Student()
{
    cout << "Student destructed" << endl;
}

bool Student :: IsInfected()
{
    if (antibodies == 0)
        return true;
    else
        return false;
}

bool Student :: ShouldBeVisible()
{
    if (!(this->IsInfected()))
        return true;
    else
        return false;

}        

void Student :: StartLearning(unsigned int num_assignments)
{
    if(current_class == NULL || GetDistanceBetween(this->location,current_class->GetLocation()) != 0) //Check to see if student is in class
    {
        cout << display_code << " " << id_num << " : I can only learn in a classroom" << endl;
    }
    else if (this->IsInfected())
    {
        cout << display_code << " " << id_num << " : I am infected so no more school for me..." << endl;
    }
    else if (dollars < current_class->GetDollarCost(num_assignments))
    {
        cout << display_code << " " << id_num << " : Not enough money for school" << endl;
    }
    else
    {
        state = STUDYING_IN_CLASS;
        unsigned int credits_to_buy = (current_class->TrainStudents(num_assignments));
        assignments_to_buy = credits_to_buy/(current_class->GetCreditsPerAssignment());
        cout << display_code << " " << id_num << " : Started to learn at the ClassRoom " << current_class->GetId() << " with " << num_assignments << " assignments" << endl;
    }
}

void Student :: StartRecoveringAntibodies(unsigned int num_vaccines)
{   
    if(current_office == NULL || GetDistanceBetween(this->location,current_office->GetLocation()) != 0) //Check to see if student is in office
    {
        cout << display_code << " " << id_num << " : I can only recover antibodies at a Doctor's Office" << endl;
    }
    else if ((current_office->GetNumVaccineRemaining()) < 1)
    {
        cout << display_code << " " << id_num << " : Cannot recover! No vaccine remaining in this Doctor's Office" << endl;
    }
    else if(!(current_office->CanAffordVaccine(num_vaccines,dollars)))
    {
        cout << display_code << " " << id_num << " : Not enough money to recover antibodies." << endl;
    }
    else
    {
        state = RECOVERING_ANTIBODIES;
        vaccines_to_buy = current_office->DistributeVaccine(num_vaccines);
        cout << display_code << " " << id_num << " : Started recovering " << vaccines_to_buy << " vaccines at Doctor's Office " << (current_office->GetId()) << endl;
    }

}

void Student :: Stop()
{
    state = STOPPED;
    cout << display_code << " " << id_num << " : Stopping.." << endl;
}

void Student :: SetupDestination(Point2D dest)
{
    destination = dest;
    delta = (destination - location)*(speed/GetDistanceBetween(destination,location));
}

void Student :: StartMoving(Point2D dest)
{
    SetupDestination(dest);
    if(state == IN_CLASS && GetDistanceBetween(destination, current_class->GetLocation()))
    {
        current_class->RemoveOneStudent();
    }
    if(state == AT_DOCTORS && GetDistanceBetween(destination,current_office->GetLocation()))
    {
        current_office -> RemoveOneStudent();
    } 
    if(state == AT_HOSPITAL && GetDistanceBetween(destination,current_hospital->GetLocation())) //Check to see if we need to remove a student
    {
        current_hospital -> RemoveOneStudent();
    }

    if (GetDistanceBetween(destination,location) == 0)
    {
        cout << display_code << " " << id_num << " : I'm already there. See?" << endl;
    }
    else if (this->IsInfected())
    {
        cout <<  display_code << " " << id_num << " : I am infected. I may move but you cannot see me." << endl;
    }
    else
    {
        cout <<  display_code << " " << id_num << " : On my way" << endl;
         state = MOVING;
    }
}

void Student :: StartMovingToClass(ClassRoom* classr)
{
    SetupDestination(classr ->GetLocation());

     if(state == IN_CLASS && GetDistanceBetween(destination, current_class->GetLocation())) //Check to see if we need to remove a student
    {
        current_class->RemoveOneStudent();
    }
    if(state == AT_DOCTORS && GetDistanceBetween(destination,current_office->GetLocation())) //Check to see if we need to remove a student
    {
        current_office -> RemoveOneStudent();
    }

    if(state == AT_HOSPITAL && GetDistanceBetween(destination,current_hospital->GetLocation())) //Check to see if we need to remove a student
    {
        current_hospital -> RemoveOneStudent();
    }

    if (this->IsInfected())
    {
        cout << display_code << " " << id_num << " : I am infected so I can't move to class... " << endl;
    }
    else if (GetDistanceBetween(this->location,classr->GetLocation()) == 0)
    {
        cout << display_code << " " << id_num << " : I am already at the Classroom!" << endl;
    }
    else
    {
        state = MOVING_TO_CLASS;
        current_class = classr;
        cout << display_code << " " << id_num << " : on my way to class " << classr->GetId() << endl;
    }

}

void Student :: StartMovingToDoctor(DoctorsOffice* office)
{
    SetupDestination(office->GetLocation());

     if(state == IN_CLASS && GetDistanceBetween(destination, current_class->GetLocation())) //Check to see if we need to remove a student
    {
        current_class->RemoveOneStudent();
    }
    if(state == AT_DOCTORS && GetDistanceBetween(destination,current_office->GetLocation())) //Check to see if we need to remove a student
    {
        current_office -> RemoveOneStudent();
    }
    
    if(state == AT_HOSPITAL && GetDistanceBetween(destination,current_hospital->GetLocation())) //Check to see if we need to remove a student
    {
        current_hospital -> RemoveOneStudent();
    }
    
    if(this->IsInfected())
    {
        cout << display_code << " " << id_num << " : I am infected so I should have gone to the doctor's.." << endl;
    }
    else if(GetDistanceBetween(this->location,office->GetLocation()) == 0)
    {
        cout << display_code << " " << id_num << " : I am already at the Doctor's!" << endl;
    }
    else
    {
        state = MOVING_TO_DOCTOR;
        current_office = office;
        cout << display_code << " " << id_num << " : On my way to the doctor's " << office->GetId() << endl;
    }
}

void Student :: WithinRange(Virus* virus)
{
    
    if((fabs(virus->GetLocation().x - this->location.x)) <= 1 && (fabs(virus->GetLocation().y - this->location.y) <= 1))
    {
        if(virus->get_in_student())
        {
            //cout << "The virus has already infected someone" << endl;
        }
        else if(!virus -> IsAlive())
        {
            cout << "Whoo! The virus I passed by is dead" << endl;
        }
        else if(this->HasVirus())
        {
            //cout << "This student is already infected" << endl;
        }
        else
        {
            virus->infect(this);
            current_virus = virus;
        }
    }
}

bool Student :: HasVirus()
{
    if(current_virus != NULL)
        if(current_virus->IsAlive())
            return true;
    return false;
}

bool Student :: UpdateLocation()
{
    Vector2D difference = destination - location;

    if ((fabs(difference.x) <= fabs(delta.x)) && (fabs(difference.y) <= fabs(delta.y)))
    {
        location = destination;
        cout << display_code << " " << id_num << " : I'm there!" << endl;
        if(this->HasVirus())
        {
            current_virus->UpdateLocation(this->location);
        }
        return true;
    }
    else
    {
        location = location+delta;
        cout << display_code << " " << id_num << " : step..." << endl;
        if(this->HasVirus())
        {
            current_virus->UpdateLocation(this->location);
        }
        return false;
    }
}

void Student :: ShowStatus()
{
    
    cout << name << " status: " << endl;
    GameObject :: ShowStatus();
    switch(state)
    {
        case STOPPED : cout << " stopped" << endl;
            break;
        case MOVING : cout << "moving at a speed of " << this->speed << " to destination " << this->destination << " at each step of " << this->delta << endl;
            break;
        case MOVING_TO_CLASS: cout << "heading to ClassRoom " << current_class->GetId() << " located at " << this->destination << " at a speed of " << this->speed << " at each step of " << this->delta << endl;
            break;
        case MOVING_TO_DOCTOR: cout << "heading to Doctor's Office " << current_office->GetId() << " at a speed of " << this->speed  << " at each step of " << this->delta << endl;
            break;
        case IN_CLASS: cout << "inside ClassRoom " << current_class->GetId() << endl;
            break;
        case AT_DOCTORS: cout << "inside Doctor's Office " << current_office->GetId() << endl;
            break;
        case STUDYING_IN_CLASS: cout << "studying in ClassRoom " << current_class->GetId() << endl; 
            break;
        case RECOVERING_ANTIBODIES: cout << "recovering antibodies in Doctor's Office " << current_office->GetId() << endl;
            break;
        case MOVING_TO_HOSPITAL: cout << "heading to Hospital " << current_hospital->GetId() << " at speed of " << this->speed << " at each step of " << this->delta << endl;
            break;
        case AT_HOSPITAL: cout << "inside Hospital " << current_hospital->GetId() << endl;
            break;
        case BOOSTING_ANTIBODIES: cout << "Getting booster shot in Hospital " << current_hospital->GetId() << endl;
            break;
        case CURING_VIRUS: cout << "Curing myself of virus " << current_virus->GetName() << " at Hospital " << current_hospital->GetId() << endl;
            break;    
    }
}


bool Student :: Update()
{
    if(this->HasVirus())
    {
        if (antibodies >= current_virus->get_virulence())
            antibodies -= current_virus->get_virulence();
        else
            antibodies = 0;
        cout << name << " is suffering from a virus and is losing antibodies fast" << endl;

    }
    
    
    if (this->IsInfected())
    {
        this->Stop();
        current_virus->ClearVirus();
        state = INFECTED;
        cout << this->name << " is out of antibodies and can't move" << endl;
        return false;
    }
        
    else if(state == STOPPED)
    {
        cout << this->name << " status: " << endl;
        cout << "Antibodies: " << antibodies << endl;
        cout << "Dollars: " << dollars << endl;
        cout << "Credits: " << credits << endl;
        return false;

    }
    else if (state == MOVING)
    {
        antibodies -= 1;
        dollars += GetRandomAmountOfDollars();
        cout << this->name << " status: " << endl;
        cout << "Antibodies: " << antibodies << endl;
        cout << "Dollars: " << dollars << endl;
        cout << "Credits: " << credits << endl;
        
        
        if(UpdateLocation())
        {
            state = STOPPED;
            return true;
        }
        else
        {
            return false;
        }
    }

    else if (state == MOVING_TO_CLASS)
    {
        antibodies -= 1;
        dollars += GetRandomAmountOfDollars();
        cout << this->name << " status: " << endl;
        cout << "Antibodies: " << antibodies << endl;
        cout << "Dollars: " << dollars << endl;
        cout << "Credits: " << credits << endl;
        
        if(UpdateLocation())
        {
            state = IN_CLASS;
            current_class->AddOneStudent();
            return true;
        }
        else
        {
            return false;
        }
    }

    else if (state == MOVING_TO_DOCTOR)
    {
        antibodies -= 1;
        dollars += GetRandomAmountOfDollars();
        cout << this->name << " status: " << endl;
        cout << "Antibodies: " << antibodies << endl;
        cout << "Dollars: " << dollars << endl;
        cout << "Credits: " << credits << endl;
        
        if(UpdateLocation())
        {
            state = AT_DOCTORS;
            current_office->AddOneStudent();
            return true;
        }
        else
        {
            return false;
        }
    }

    else if (state == IN_CLASS)
    {
        cout << this->name << " status: " << endl;
        cout << "Antibodies: " << antibodies << endl;
        cout << "Dollars: " << dollars << endl;
        cout << "Credits: " << credits << endl;
        return false;
    }

    else if (state == AT_DOCTORS)
    {
        cout << this->name << " status: " << endl;
        cout << "Antibodies: " << antibodies << endl;
        cout << "Dollars: " << dollars << endl;
        cout << "Credits: " << credits << endl;
        return false;
    }

    else if (state == STUDYING_IN_CLASS)
    {   
        antibodies -= (current_class->GetAntibodyCost(assignments_to_buy));
        dollars -= (current_class->GetDollarCost((assignments_to_buy)));
        credits += (assignments_to_buy*(current_class->GetCreditsPerAssignment()));
        state = IN_CLASS;
        cout << name << " completed " << assignments_to_buy << " assignment(s)!" << endl;
        cout << name << " gained " << (assignments_to_buy*(current_class->GetCreditsPerAssignment())) << " credit(s)" << endl;
        cout << this->name << " status: " << endl;
        cout << "Antibodies: " << antibodies << endl;
        cout << "Dollars: " << dollars << endl;
        cout << "Credits: " << credits << endl;
        return true;
    }

    else if (state == RECOVERING_ANTIBODIES)
    {
        dollars -=  current_office->GetDollarCost(vaccines_to_buy);
        unsigned int antibodies_gained = 5*vaccines_to_buy;
        antibodies += antibodies_gained;
        cout << "** " << name << " recovered " << antibodies_gained << " antibodies!**" << endl;
        cout << "** " << name << " bought " << vaccines_to_buy << " vaccine(s)!**" << endl;
        cout << this->name << " status: " << endl;
        cout << "Antibodies: " << antibodies << endl;
        cout << "Dollars: " << dollars << endl;
        cout << "Credits: " << credits << endl; 
        state = AT_DOCTORS;
        return true;
    }
    //Updated states for Hospital
    else if (state == MOVING_TO_HOSPITAL)
    {
        antibodies -= 1;
        dollars += GetRandomAmountOfDollars();
        cout << this->name << " status: " << endl;
        cout << "Antibodies: " << antibodies << endl;
        cout << "Dollars: " << dollars << endl;
        cout << "Credits: " << credits << endl;
        
        if(UpdateLocation())
        {
            state = AT_HOSPITAL;
            current_hospital->AddOneStudent();
            return true;
        }
        else
        {
            return false;
        } 
    }
    else if(state == AT_HOSPITAL)
    {
        cout << this->name << " status: " << endl;
        cout << "Antibodies: " << antibodies << endl;
        cout << "Dollars: " << dollars << endl;
        cout << "Credits: " << credits << endl;
        return false; 
    }
    else if (state == BOOSTING_ANTIBODIES)
    {
        dollars -= current_hospital->GetBoosterShotCost();
        unsigned int antibodies_gained = antibodies;
        antibodies += antibodies_gained;
        cout <<"** " << name << " boosted " << antibodies_gained << " antibodies!**" << endl;
        cout << this->name << "status: " << endl;
        cout << "Antibodies: " << antibodies << endl;
        cout << "Dollars: " << dollars << endl;
        cout << "Credits: " << credits << endl; 
        state = AT_HOSPITAL;
        return true;
    }
    else if (state == CURING_VIRUS)
    {
        dollars -= current_hospital->GetVirusCureCost(current_virus->get_resistance());
        current_virus->KillVirus();
        this->current_virus = NULL;
        cout <<"** " << name << " cured itself of a virus" << endl;
        cout << "Antibodies: " << antibodies << endl;
        cout << "Dollars: " << dollars << endl;
        cout << "Credits: " << credits << endl; 
        state = AT_HOSPITAL;
        return true;
    }
    return false;
}



double GetRandomAmountOfDollars()
{
    srand(time(NULL));
    double dollar_amount = (double)rand()/RAND_MAX;
    return dollar_amount*(2.0-0.0);
}

//Function added to make it possible to access student name
string Student :: GetName()
{
    return name;
}

//Functions for Hospital
void Student :: StartMovingToHospital(Hospital* hospital)
{
    SetupDestination(hospital ->GetLocation());

     if(state == IN_CLASS && GetDistanceBetween(destination, current_class->GetLocation())) //Check to see if we need to remove a student
    {
        current_class->RemoveOneStudent();
    }
    if(state == AT_DOCTORS && GetDistanceBetween(destination,current_office->GetLocation())) //Check to see if we need to remove a student
    {
        current_office -> RemoveOneStudent();
    }
    if(state == AT_HOSPITAL && GetDistanceBetween(destination,current_hospital->GetLocation())) //Check to see if we need to remove a student
    {
        current_hospital -> RemoveOneStudent();
    }

    if (this->IsInfected())
    {
        cout << display_code << " " << id_num << " : I am infected so I can't move to hospital... " << endl;
    }
    else if (GetDistanceBetween(this->location,hospital->GetLocation()) == 0)
    {
        cout << display_code << " " << id_num << " : I am already at the Hospital" << endl;
    }
    else
    {
        state = MOVING_TO_HOSPITAL;
        current_hospital = hospital;
        cout << display_code << " " << id_num << " : on my way to hospital " << hospital->GetId() << endl;
    }
}

void Student :: GetBooster()
{   
    if(current_hospital == NULL || GetDistanceBetween(this->location,current_hospital->GetLocation()) != 0) //Check to see if student is in hospital
    {
        cout << display_code << " " << id_num << " : I can only get a booster shot at a Hospital" << endl;
    }
    else if (!(current_hospital->HasBoosterShot()))
    {
        cout << display_code << " " << id_num << " : Cannot recover! No booster shots remaining in this Hospital" << endl;
    }
    else if(current_hospital->GetBoosterShotCost() > dollars)
    {
        cout << display_code << " " << id_num << " : Not enough money to buy booster shots." << endl;
    }
    else
    {
        state = BOOSTING_ANTIBODIES;
        boosters_to_buy = current_hospital->DistributeBoosterShot();
        cout << display_code << " " << id_num << " : Started boosting " << boosters_to_buy << " booster shots at Hospital " << (current_hospital->GetId()) << endl;
    }
}

void Student :: GetCure()
{
    if(current_hospital == NULL || GetDistanceBetween(this->location,current_hospital->GetLocation()) != 0) //Check to see if student is in hospital
    {
        cout << display_code << " " << id_num << " : I can only get a cure at a Hospital" << endl;
    }
    else if(current_virus == NULL)
    {
        cout << display_code << " " << id_num << " : I don't need a cure" << endl;
    }
    else if(current_hospital->GetVirusCureCost(current_virus->get_resistance())> dollars)
    {
        cout << display_code << " " << id_num << " : I can't afford the cure" << endl;
    }
    else
    {
        state = CURING_VIRUS;
        cout << display_code << " " << id_num << " : Started curing myself at Hospital " << (current_hospital->GetId()) << endl;
    }
}