#Variables to control makefile operation

CC = g++
CFLAGS = -Wall -g

#Targets needed to bring the executable up to date
main: piece.o main.o #InputLayer.o  OutputLayer.o NeuralNetwork.o main.o
	$(CC) $(CFLAGS) -o main piece.o  main.o

main.o: main.cpp piece.h #HiddenLayer.h HiddenNeuron.h OutputLayer.h NeuralNetwork.h
	$(CC) $(CFLAGS) -c main.cpp

piece.o: piece.h

#HiddenNeuron.o: HiddenNeuron.cpp HiddenNeuron.h HiddenLayer.h InputLayer.h
#	$(CC) $(CFLAGS) -c HiddenNeuron.cpp
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