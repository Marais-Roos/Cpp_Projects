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
#HiddenLayer.o: HiddenLayer.cpp HiddenLayer.h HiddenNeuron.h
#	$(CC) $(CFLAGS) -c HiddenLayer.cpp
#
#OutputLayer.o: OutputLayer.cpp OutputLayer.h HiddenLayer.h
#	$(CC) $(CFLAGS) -c OutputLayer.cpp
#
#NeuralNetwork.o: NeuralNetwork.cpp NeuralNetwork.h OutputLayer.h HiddenLayer.h InputLayer.h
#	$(CC) $(CFLAGS) -c NeuralNetwork.cpp

#Makefile commands
run:
	./main

clean:
	rm -f *.o main

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./main