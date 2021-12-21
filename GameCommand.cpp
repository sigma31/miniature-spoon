#include "GameCommand.h"

void DoMoveCommand(Model& model, int student_id, Point2D p1)
{
    Student* StudentA = model.GetStudentPtr(student_id);
     if(StudentA == nullptr)
    {
        throw Invalid_Input("Please enter the ID of an existing student");
        //cout <<"Error: Please enter a valid command" << endl;
    }
    else
    {
        StudentA->StartMoving(p1);
        cout << "Moving " << StudentA->GetName() << " to " << p1 << endl;
    }
}

void DoMoveToDoctorCommand(Model& model, int student_id, int doctor_id)
{
    Student* StudentA = model.GetStudentPtr(student_id);
    DoctorsOffice* DoctorA = model.GetDoctorsOfficePtr(doctor_id);
    if(StudentA == nullptr || DoctorA == nullptr)
    {
        throw Invalid_Input("Please enter the IDs of existing objects");
        //cout << "Error: Please enter a valid command" << endl;
    }
    else
    {
        StudentA->StartMovingToDoctor(DoctorA);
        cout << "Moving " << StudentA->GetName() << " to doctors office " << DoctorA->GetId() << endl;
    }
}

void DoMoveToClassCommand(Model& model, int student_id, int class_id)
{
    Student* StudentA = model.GetStudentPtr(student_id);
    ClassRoom* ClassA = model.GetClassRoomPtr(class_id);
    if(StudentA == nullptr || ClassA == nullptr)
    {
        throw Invalid_Input("Please enter the IDs of existing objects");
        //cout << "Error: Please enter a valid command" << endl;
    }
    else
    {
        StudentA->StartMovingToClass(ClassA);
        cout << "Moving " << StudentA->GetName() << " to class " << ClassA->GetId() << endl;
    }
}

void DoStopCommand(Model& model, int student_id)
{
    Student* StudentA = model.GetStudentPtr(student_id);
    if(StudentA == 0)
    {
        throw Invalid_Input("Please enter the ID of an existing student");
        //cout << "Error: Please enter a valid command" << endl;
    }
    else
    {
        StudentA->Stop();
        cout << "Stopping " << StudentA->GetName() << endl;
    }
}

void DoLearningCommand(Model& model, int student_id, unsigned int assignments)
{
    Student* StudentA = model.GetStudentPtr(student_id);
    if(StudentA == 0)
    {
        throw Invalid_Input("Please enter the ID of a existing student");
        //cout << "Error: Please enter a valid command" << endl;
    }
    else
    {
        StudentA->StartLearning(assignments);
        cout << "Teaching " << StudentA->GetName() << endl;
    }
}

void DoRecoverInOfficeCommand(Model& model, int student_id, unsigned int vaccine_needs)
{
    Student* StudentA = model.GetStudentPtr(student_id);
    if(StudentA == 0)
    {
        throw Invalid_Input("Please enter the ID of a existing student");
        //cout << "Error: Please enter a valid command" << endl;
    }
    else
    {
        StudentA->StartRecoveringAntibodies(vaccine_needs);
        cout <<"Recovering " << StudentA->GetName() << "'s antibodies" << endl;
    }
}

void DoGoCommand(Model& model, View& view)
{
    cout << "Advancing one tick." << endl;
    model.Update();
    model.ShowStatus();
    view.Clear();
    model.Display(view);
    view.Draw();
}

void DoRunCommand(Model& model, View& view)
{
    for(int i = 0; i < 5; i++)
    {
        if(model.Update())
        {
            break;
        }
    }
    cout << "Advancing one event" << endl;
    model.ShowStatus();
    view.Clear();
    model.Display(view);
    view.Draw();
}

//Hospital Related Game Commands
void DoMoveToHospitalCommand(Model& model, int student_id, int hospital_id)
{
   Student* StudentA = model.GetStudentPtr(student_id);
    Hospital* HospitalA = model.GetHospitalPtr(hospital_id);
    if(StudentA == nullptr || HospitalA == nullptr)
    {
        throw Invalid_Input("Please enter the IDs of existing objects");
        //cout << "Error: Please enter a valid command" << endl;
    }
    else
    {
        StudentA->StartMovingToHospital(HospitalA);
        cout << "Moving " << StudentA->GetName() << " to hospital " << HospitalA->GetId() << endl;
    } 
}

void DoBoostInHospital(Model& model, int student_id)
{
 Student* StudentA = model.GetStudentPtr(student_id);
    if(StudentA == 0)
    {
        throw Invalid_Input("Please enter the ID of a existing student");
        //cout << "Error: Please enter a valid command" << endl;
    }
    else
    {
        StudentA->GetBooster();
        cout <<"Boosting " << StudentA->GetName() << "'s antibodies" << endl;
    }   
}

void DoCureInHospital(Model& model, int student_id)
{
    Student* StudentA = model.GetStudentPtr(student_id);
    if(StudentA == 0)
    {
        throw Invalid_Input("Please enter the ID of a existing student");
        //cout << "Error: Please enter a valid command" << endl;
    }
    else
    {
        StudentA->GetCure();
        cout <<"Curing " << StudentA->GetName() << " of virus" << endl;
    } 
}