#Variables to control makefile operation

CC = g++
CFLAGS = -Wall -g

#Targets needed to bring the executable up to date
main: main.o InputLayer.o
	$(CC) $(CFLAGS) -o main main.o InputLayer.o

main.o: main.cpp InputLayer.h
	$(CC) $(CFLAGS) -c main.cpp

InputLayer.o: InputLayer.h

#Makefile commands
run:
	./main

clean:
	rm -f *.o main

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./main