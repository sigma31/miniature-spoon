#include "Vector2D.h"
#include "Point2D.h"
#include "GameObject.h"
#include "Building.h"
#include "ClassRoom.h"
#include "DoctorsOffice.h"
#include "Student.h"
#include "Model.h"
#include "GameCommand.h"
#include <vector>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <stdexcept>
//#include "Input_Handling.h"

using namespace std;
int main()
{
    Model model;
    View view;
    string userinput;
    char command, type;
    int ID1, ID2;
    double x,y;
    model.ShowStatus();
    view.Clear();
    model.Display(view);
    view.Draw();
    
    
    while(true)
    {
        cout << "Enter the game command:" << endl;
        //Input handling done using vectors and switch statements
        getline(cin,userinput);
        vector <string> tokens;
        stringstream check(userinput);
        string intermediate;
        while(getline(check, intermediate, ' '))
        {
            tokens.push_back(intermediate);
        }
        try{
        if(tokens.size() == 5)
        {
            command = (tokens[0])[0];
            type = (tokens[1])[0];
            ID1 = stoi(tokens[2]);
            x = stod(tokens[3]);
            y = stod(tokens[4]);
        }
        else if(tokens.size() == 4)
        {
            command = (tokens[0])[0];
            ID1 = stoi(tokens[1]);
            x = stod(tokens[2]);
            y = stod(tokens[3]);
        }
        else if (tokens.size() == 3)
        {
            command = (tokens[0])[0];
            ID1 = stoi(tokens[1]);
            ID2 = stoi(tokens[2]);
        }
        else if (tokens.size() == 2)
        {
            command = (tokens[0])[0];
            ID1 = stoi(tokens[1]);
        }
        else
        {
            command = (tokens[0])[0];
        }
        }

        catch(const std:: invalid_argument &e)
        {
            cout << "Please follow the format while inputting commands" << endl;
            continue;
        }

        try{
            switch(command)
            {
                case 'n':
                if(type != 'd' && type != 'c' && type != 's' && type != 'v' && type != 'h')
                {
                    throw Invalid_Input("Was expecting a recognizable TYPE");
                }
                if(ID1 > 9 || ID1 < 0)
                {
                    throw Invalid_Input("Sorry but the game only supports ID between 0 and 9");
                }
                if(x > 20 || x < 0 || y > 20 || y < 0)
                {
                    throw Invalid_Input("Please enter coordinates within the grid");
                }
                model.NewCommand(type,ID1,x,y);
                break;
                case 'm': 
                if(x > 20 || x < 0 || y > 20 || y < 0)
                {
                    throw Invalid_Input("Please enter coordinates within the grid");
                }
                DoMoveCommand(model,ID1,Point2D(x,y));
                break;
                case 'd':
                DoMoveToDoctorCommand(model,ID1,ID2);
                break;
                case 'c':
                DoMoveToClassCommand(model,ID1,ID2);
                break;
                case 's':
                DoStopCommand(model, ID1);
                cout << "Stopping student " << ID1 << endl;
                break;
                case 'v':
                DoRecoverInOfficeCommand(model,ID1,ID2);
                if(ID2 < 0)
                {
                    throw Invalid_Input("Cannot buy negative number of vaccines");
                }
                cout << "Buying vaccines" << endl;
                break;
                case 'a':
                DoLearningCommand(model,ID1,ID2);
                if(ID2 < 0)
                {
                    throw Invalid_Input("Cannot learn negative number of assignments");
                }
                cout << "Completing assignments" << endl;
                break;
                case 'g':
                DoGoCommand(model,view);
                break;
                case 'r':
                DoRunCommand(model,view);
                break;
                case 'q':
                cout << "Quitting game" << endl;
                return 0;
                break;
                //Commands related to Hospital
                case 'h':
                DoMoveToHospitalCommand(model, ID1,ID2);
                cout << "Started moving to Hospital" << endl;
                break;
                case 'b':
                DoBoostInHospital(model, ID1);
                cout << "Getting booster in Hospital" << endl;
                break;
                case 'l':
                DoCureInHospital(model, ID1);
                cout << "Curing in Hospital" << endl;
                break;
                default:
                throw Invalid_Input("Please enter a valid command code");
            }
        }

        catch(Invalid_Input& except)
        {
            cout << "Invalid input - " << except.msg_ptr << endl;
        }
    }

}