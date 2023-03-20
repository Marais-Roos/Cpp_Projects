#Variables to control makefile operation
CC = g++
CFLAGS = -Wall -g

#Targets needde to bring the executable up to date

main: main.o Controller.o Babushka.o BlueBabushka.o DarkBlueBabushka.o LightBlueBabushka.o GoldBabushka.o GreenBabushka.o RedBabushka.o YellowBabushka.o DisplacementException.o OverflowException.o RotateException.o UnderflowException.o ControllerException.o
	$(CC) $(CFLAGS) -o main main.o Controller.o Babushka.o BlueBabushka.o DarkBlueBabushka.o LightBlueBabushka.o GoldBabushka.o GreenBabushka.o RedBabushka.o YellowBabushka.o DisplacementException.o OverflowException.o RotateException.o UnderflowException.o ControllerException.o

main.o: main.cpp Controller.h
	$(CC) $(CFLAGS) -c main.cpp

Babushka.o: Babushka.h Babushka.cpp
	$(CC) $(CFLAGS) -c Babushka.cpp
	
BlueBabushka.o: BlueBabushka.h BlueBabushka.cpp OverflowException.h UnderflowException.h
	$(CC) $(CFLAGS) -c BlueBabushka.cpp
	
DarkBlueBabushka.o: DarkBlueBabushka.h DarkBlueBabushka.cpp BlueBabushka.h
	$(CC) $(CFLAGS) -c DarkBlueBabushka.cpp
	
LightBlueBabushka.o: LightBlueBabushka.h LightBlueBabushka.cpp BlueBabushka.h
	$(CC) $(CFLAGS) -c LightBlueBabushka.cpp
	
GoldBabushka.o: GoldBabushka.h GoldBabushka.cpp OverflowException.h UnderflowException.h
	$(CC) $(CFLAGS) -c GoldBabushka.cpp
	
GreenBabushka.o: GreenBabushka.h GreenBabushka.cpp DisplacementException.h
	$(CC) $(CFLAGS) -c GreenBabushka.cpp
	
RedBabushka.o: RedBabushka.h RedBabushka.cpp RotateException.h
	$(CC) $(CFLAGS) -c RedBabushka.cpp
	
YellowBabushka.o: YellowBabushka.h YellowBabushka.cpp
	$(CC) $(CFLAGS) -c YellowBabushka.cpp
	
DisplacementException.o: DisplacementException.h DisplacementException.cpp BabushkaException.h
	$(CC) $(CFLAGS) -c DisplacementException.cpp
	
OverflowException.o: OverflowException.h OverflowException.cpp BabushkaException.h
	$(CC) $(CFLAGS) -c OverflowException.cpp
	
RotateException.o: RotateException.h RotateException.cpp BabushkaException.h
	$(CC) $(CFLAGS) -c RotateException.cpp
	
UnderflowException.o: UnderflowException.h UnderflowException.cpp BabushkaException.h
	$(CC) $(CFLAGS) -c UnderflowException.cpp
	
Controller.o: Controller.h Controller.cpp Babushka.h ReturnStruct.h DarkBlueBabushka.h LightBlueBabushka.h GoldBabushka.h GreenBabushka.h RedBabushka.h YellowBabushka.h ControllerException.h
	$(CC) $(CFLAGS) -c Controller.cpp
	
ControllerException.o: ControllerException.h ControllerException.cpp BabushkaException.h
	$(CC) $(CFLAGS) -c ControllerException.cpp
	
#Makefile commands
run:
	./main

clean: 
	rm -f *.o main

valgrind: 
	valgrind --tool=memcheck --leak-check=yes ./main