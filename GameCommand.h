#include "Model.h"

void UserInputCommand(string);
void DoMoveCommand(Model&,int,Point2D);
void DoMoveToDoctorCommand(Model&, int, int);
void DoMoveToClassCommand(Model&,int,int);
void DoStopCommand(Model&,int);
void DoLearningCommand(Model&, int, unsigned int);
void DoRecoverInOfficeCommand(Model&, int, unsigned int);
void DoGoCommand(Model&, View&);
void DoRunCommand(Model&, View&);

//Hospital Related Game Commands
void DoMoveToHospitalCommand(Model&,int,int);
void DoBoostInHospital(Model&, int);
void DoCureInHospital(Model&, int);


