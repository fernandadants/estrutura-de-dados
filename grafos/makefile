CC = g++
CFLAGS = -Wall -g -std=c++11

all: grafo

grafo: main.o grafo.o	
	$(CC) $(CFLAGS) -o grafo main.o grafo.o

main.o: main.cpp grafo.h
	$(CC) $(CFLAGS) -c main.cpp

grafo.o: grafo.cpp grafo.h
	$(CC) $(CFLAGS) -c grafo.cpp

clean:
	rm -f *.o grafo