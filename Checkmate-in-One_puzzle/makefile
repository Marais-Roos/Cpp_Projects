#Variables to control makefile operation

CC = g++
CFLAGS = -Wall -g

#Targets needed to bring the executable up to date
main: main.o board.o  piece.o #NeuralNetwork.o main.o
	$(CC) $(CFLAGS) -o main main.o piece.o board.o

main.o: main.cpp piece.h board.h #HiddenLayer.h HiddenNeuron.h OutputLayer.h NeuralNetwork.h
	$(CC) $(CFLAGS) -c main.cpp

piece.o: piece.cpp piece.h
	$(CC) $(CFLAGS) -c piece.cpp

board.o: board.cpp board.h piece.h
	$(CC) $(CFLAGS) -c board.cpp
#

#Makefile commands
run:
	./main

clean:
	rm -f *.o main

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./main