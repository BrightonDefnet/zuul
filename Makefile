all: zuul

zuul: main.o Player.o Room.o
	g++ -o zuul main.o Player.o Room.o

main.o: main.cpp
	g++ -c main.cpp

Player.o: Player.cpp Player.h
	g++ -c Player.cpp

Room.o: Room.cpp Room.h
	g++ -c Room.cpp
