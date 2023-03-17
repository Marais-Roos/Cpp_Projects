#Variables to control makefile operation

CC = g++
CFLAGS = -Wall -g

#Targets needed to bring the executable up to date
main: main.o board.o  piece.o solver.o
	$(CC) $(CFLAGS) -o main main.o piece.o board.o solver.o

main.o: main.cpp piece.h board.h solver.h
	$(CC) $(CFLAGS) -c main.cpp

piece.o: piece.cpp piece.h
	$(CC) $(CFLAGS) -c piece.cpp

board.o: board.cpp board.h piece.h
	$(CC) $(CFLAGS) -c board.cpp

solver.o: solver.cpp solver.h board.h
	$(CC) $(CFLAGS) -c solver.cpp

#Makefile commands
run:
	./main

clean:
	rm -f *.o main

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./main