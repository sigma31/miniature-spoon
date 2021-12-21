CC=g++ -std=c++11 -g

OBJS=main.o Building.o Point2D.o Vector2D.o GameObject.o GameCommand.o DoctorsOffice.o Model.o Student.o ClassRoom.o View.o Virus.o Hospital.o

default: PA3

PA3: $(OBJS)
	$(CC) -o PA3 $(OBJS) 

Vector2D.o: Vector2D.cpp Vector2D.h
	$(CC) -c Vector2D.cpp -o Vector2D.o 
	
Point2D.o: Point2D.cpp Point2D.h Vector2D.h
	$(CC) -c Point2D.cpp -o Point2D.o 

Building.o: Building.cpp Building.h
	$(CC) -c Building.cpp -o Building.o

GameObject.o: GameObject.cpp GameObject.h Point2D.h Vector2D.h
	$(CC) -c GameObject.cpp -o GameObject.o 

DoctorsOffice.o: DoctorsOffice.cpp DoctorsOffice.h GameObject.h Point2D.h
	$(CC) -c DoctorsOffice.cpp -o DoctorsOffice.o

Model.o: Model.cpp Model.h GameObject.h Student.h ClassRoom.h DoctorsOffice.h View.h
	$(CC) -c Model.cpp -o Model.o 

ClassRoom.o: ClassRoom.cpp ClassRoom.h GameObject.h Point2D.h
	$(CC) -c ClassRoom.cpp -o ClassRoom.o

View.o: View.cpp View.h GameObject.h Point2D.h
	$(CC) -c View.cpp -o View.o 

Student.o: Student.cpp Student.h GameObject.h Point2D.h Vector2D.h DoctorsOffice.h ClassRoom.h Virus.h Hospital.h
	$(CC) -c Student.cpp -o Student.o

GameCommand.o: GameCommand.cpp GameCommand.h Model.h GameObject.h Student.h ClassRoom.h DoctorsOffice.h
	$(CC) -c GameCommand.cpp -o GameCommand.o

Virus.o: Virus.cpp Virus.h 
	$(CC) -c Virus.cpp -o Virus.o

Hospital.o: Hospital.cpp Hospital.h GameObject.h Point2D.h
	$(CC) -c Hospital.cpp -o Hospital.o
	
main.o: main.cpp Building.h Point2D.h Vector2D.h GameCommand.h DoctorsOffice.h Model.h Student.h ClassRoom.h GameObject.h View.h Virus.h Hospital.h
	$(CC) -c main.cpp -o main.o

#checkpoint commands below

checkpoint1: TestCheckPoint1.cpp Point2D.o Vector2D.o GameObject.o
	$(CC) -o checkpoint1.exe TestCheckPoint1.cpp Point2D.o Vector2D.o GameObject.o
	
checkpoint2: TestCheckPoint2.cpp Point2D.o Vector2D.o GameObject.o Building.o DoctorsOffice.o ClassRoom.o
	$(CC) -o checkpoint2.exe TestCheckPoint2.cpp Point2D.o Vector2D.o GameObject.o Building.o DoctorsOffice.o ClassRoom.o
	
#add your own tests for other checkpoints here

checkpoint3: TestCheckPoint3.cpp Point2D.o Vector2D.o GameObject.o Building.o DoctorsOffice.o ClassRoom.o Student.o
	$(CC) -o checkpoint3.exe TestCheckPoint3.cpp Point2D.o Vector2D.o GameObject.o Building.o DoctorsOffice.o ClassRoom.o

checkpoint4:  main.cpp Point2D.o Vector2D.o GameObject.o Building.o DoctorsOffice.o ClassRoom.o Student.o Model.o View.o GameCommand.o
	$(CC) -g -o list.exe main.cpp Point2D.o Vector2D.o GameObject.o Building.o DoctorsOffice.o ClassRoom.o Student.o Model.o View.o GameCommand.o

checkpoint5: main.cpp Point2D.o Vector2D.o GameObject.o Building.o DoctorsOffice.o ClassRoom.o Student.o Model.o View.o GameCommand.o Virus.o
	$(CC) -g -o virus.exe main.cpp Point2D.o Vector2D.o GameObject.o Building.o DoctorsOffice.o ClassRoom.o Student.o Model.o View.o GameCommand.o Virus.o

checkpointH: testhospital.cpp Point2D.o Vector2D.o GameObject.o Building.o DoctorsOffice.o ClassRoom.o Student.o Model.o View.o GameCommand.o Virus.o Hospital.o
	$(CC) -g -o hospital.exe testhospital.cpp Point2D.o Vector2D.o GameObject.o Building.o DoctorsOffice.o ClassRoom.o Student.o Model.o View.o GameCommand.o Virus.o Hospital.o

finalcheckpoint: main.cpp Point2D.o Vector2D.o GameObject.o Building.o DoctorsOffice.o ClassRoom.o Student.o Model.o View.o GameCommand.o Virus.o Hospital.o
	$(CC) -g -o final.exe main.cpp Point2D.o Vector2D.o GameObject.o Building.o DoctorsOffice.o ClassRoom.o Student.o Model.o View.o GameCommand.o Virus.o Hospital.o

clean: 
	rm $(OBJS) PA3 *.exe

