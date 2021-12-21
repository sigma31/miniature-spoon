#include "Model.h"

Model :: Model()
{
    time = 0;
    DoctorsOffice* D1 = new DoctorsOffice(1,1,100,Point2D(1,20));
    DoctorsOffice* D2 = new DoctorsOffice(2,2,200,Point2D(10,20));
    Student* S1 = new Student("Homer",1,'S',2,Point2D(5,1));
    Student* S2 = new Student("Marge",2,'S',1,Point2D(10,1));
    ClassRoom* C1 = new ClassRoom(10,1,2,3,1,Point2D(0,0));
    ClassRoom* C2 = new ClassRoom(20,5,7.5,4,2,Point2D(5,5));
    Virus* V1 = new Virus("Common Cold",2,3,30,false,1,Point2D(15,15));
    Virus* V2 = new Virus("Covid 19",5,5,25,false,2,Point2D(5,11));
    //Added Hospital
    Hospital* H1 = new Hospital(2,15,1,Point2D(10,10));
    object_ptrs.push_back(D1);
    object_ptrs.push_back(D2);
    object_ptrs.push_back(S1);
    object_ptrs.push_back(S2);
    object_ptrs.push_back(C1);
    object_ptrs.push_back(C2);
    object_ptrs.push_back(V1);
    object_ptrs.push_back(V2);
    //Added hospital to objects
    object_ptrs.push_back(H1);
    active_ptrs.assign(object_ptrs.begin(),object_ptrs.end());

    office_ptrs.push_back(D1);
    office_ptrs.push_back(D2);
    student_ptrs.push_back(S1);
    student_ptrs.push_back(S2);
    class_ptrs.push_back(C1);
    class_ptrs.push_back(C2);
    virus_ptrs.push_back(V1);
    virus_ptrs.push_back(V2);
    //Hospital added hospital pointer list
    hospital_ptrs.push_back(H1);
    cout << "Model default constructed" << endl;
}

Model :: ~Model()
{
    for(list <GameObject*> :: iterator iter1 = object_ptrs.begin(); iter1 != object_ptrs.end(); iter1++)
    {
        delete *iter1;
    }
    cout << "Model destructed" << endl;
}

Student* Model :: GetStudentPtr(int id)
{
    for (list <Student*> :: iterator iter1 = student_ptrs.begin(); iter1 != student_ptrs.end(); iter1++)
    {
        if ((*iter1)->GetId() == id)
            return *iter1;
    }

    return nullptr;
}

DoctorsOffice* Model :: GetDoctorsOfficePtr(int id)
{
    for(list <DoctorsOffice*> :: iterator iter1 = office_ptrs.begin(); iter1 != office_ptrs.end(); iter1++)
    {
        if((*iter1)->GetId() == id)
            return *iter1;
    }
    return nullptr;
}

ClassRoom* Model :: GetClassRoomPtr(int id)
{
    for(list <ClassRoom*> :: iterator iter1 = class_ptrs.begin(); iter1 != class_ptrs.end(); iter1++)
    {
        if((*iter1)->GetId() == id)
            return *iter1; 
    }
    return nullptr;
}
//Function added to get Hospital Pointer
Hospital* Model :: GetHospitalPtr(int id)
{
    for(list <Hospital*> :: iterator iter1 = hospital_ptrs.begin(); iter1 != hospital_ptrs.end(); iter1++)
    {
        if((*iter1)->GetId() == id)
            return *iter1; 
    }
    return nullptr;
}

bool Model :: Update()
{
    time++;
    int output = 0;
    int temp1 = 0;
    int temp2 = 0;

    for(list <GameObject*> :: iterator iter = active_ptrs.begin(); iter != active_ptrs.end(); iter++)
    {
        if(!(*iter)->ShouldBeVisible())
        {
            active_ptrs.erase(iter);
            break;
        }
    }
    
    for(list <Student*> :: iterator iter = student_ptrs.begin(); iter != student_ptrs.end(); iter++)
    {
        for(list <Virus*> :: iterator iter1 = virus_ptrs.begin(); iter1 != virus_ptrs.end(); iter1++)
        {
            (*iter)->WithinRange(*iter1);
        }
    }
    
    list <GameObject*> :: iterator iter1;
    for(iter1 = active_ptrs.begin(); iter1 != active_ptrs.end(); iter1++)
    {
        if((*iter1)->Update() == true)
        {
            output++;
        }
    }
    
    list <ClassRoom*> :: iterator iter2;
    for(iter2 = class_ptrs.begin(); iter2 != class_ptrs.end(); iter2++)
    {
        if((*iter2)->GetNumAssignmentsRemaining() == 0)
        {
            temp1++;
        }
    }

    list<Student*> :: iterator iter3;
    for(iter3 = student_ptrs.begin(); iter3 != student_ptrs.end(); iter3++)
    {
        if((*iter3)->IsInfected())
        {
            temp2++;
        }
    }

    if (temp1 == class_ptrs.size())
    {
        cout << "GAME OVER: You win! All assignments done!" << endl;
        exit(0);
    }

    if(temp2 == student_ptrs.size())
    {
        cout << "GAME OVER: You lose! All of your Students are infected!" << endl;
        exit(0);
    }

    if(output > 0)
    {
        return true;
    }

    return false;
}

void Model :: Display(View& view)
{
    for ( list<GameObject*> :: iterator iter1 = active_ptrs.begin(); iter1 != active_ptrs.end(); iter1++)
    {
        view.Plot(*iter1);
    }
}

void Model :: ShowStatus()
{
    cout << "Time: " << time << endl;
    
    for(list<GameObject*> :: iterator iter1 = object_ptrs.begin(); iter1 != object_ptrs.end(); iter1++ )
    {
        (*iter1)->ShowStatus();
    }
}

void Model :: NewCommand(char type, int in_id, double x, double y)
{
    switch(type)
    {
        case 'd': 
        {
            for(list <DoctorsOffice*> :: iterator iter1 = office_ptrs.begin(); iter1 != office_ptrs.end(); iter1++)
            {
                if(in_id == (*iter1)->GetId())
                throw Invalid_Input("Sorry but please enter a Unique Doctor's Office ID");
            }
            DoctorsOffice* D = new DoctorsOffice(in_id, 100, 2, Point2D(x,y));
            object_ptrs.push_back(D);
            active_ptrs.push_back(D);
            office_ptrs.push_back(D);
            cout << "New Doctor's Office created" << endl;
            break;
        }

        case 'c':
        {    
            for(list <ClassRoom*> :: iterator iter1 = class_ptrs.begin(); iter1 != class_ptrs.end(); iter1++)
            {
                if(in_id == (*iter1)->GetId())
                throw Invalid_Input("Sorry but please enter a Unique ClassRoom ID");
            }
            ClassRoom* C = new ClassRoom(25,2,10,5,in_id,Point2D(x,y));
            object_ptrs.push_back(C);
            active_ptrs.push_back(C);
            class_ptrs.push_back(C);
            cout << "New ClassRoom created" << endl;
            break;
        }

        case 's':
        {
            for(list <Student*> :: iterator iter1 = student_ptrs.begin(); iter1 != student_ptrs.end(); iter1++)
            {
                if(in_id == (*iter1)->GetId())
                throw Invalid_Input("Sorry but please enter a Unique Student ID");
            }
            Student* S = new Student("NewStudent",in_id,'S',1,Point2D(x,y));
            object_ptrs.push_back(S);
            active_ptrs.push_back(S);
            student_ptrs.push_back(S);
            cout << "New Student created" << endl;
            break;
        }

        case 'v':
        {
            for(list <Virus*> :: iterator iter1 = virus_ptrs.begin(); iter1 != virus_ptrs.end(); iter1++)
            {
                if(in_id == (*iter1)->GetId())
                throw Invalid_Input("Sorry but please enter a Unique Virus ID");
            }
            Virus* V = new Virus("VirusX",5,10,10,false,in_id,Point2D(x,y));
            object_ptrs.push_back(V);
            active_ptrs.push_back(V);
            virus_ptrs.push_back(V);
            cout << "New Virus created" << endl;
            break;
        }
        //Added to add new hospital
        case 'h':
        {
            for(list <Hospital*> :: iterator iter1 = hospital_ptrs.begin(); iter1 != hospital_ptrs.end(); iter1++)
            {
                if(in_id == (*iter1)->GetId())
                throw Invalid_Input("Sorry but please enter a Unique Hospital ID");
            }
            Hospital* H = new Hospital(2,20,in_id,Point2D(x,y));
            object_ptrs.push_back(H);
            active_ptrs.push_back(H);
            hospital_ptrs.push_back(H);
            cout << "New Hospital created" << endl;
            break;
        } 
        default:
        cout << "Unrecognized command code for creating new object" << endl;
    }
}