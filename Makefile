main: main.cc Board.o Block.o
	g++ -DEBUG -o main main.cc Board.o Block.o -I .


Block.o: Block.h Block.cpp
	g++ -Wall -std=c++11 -DEBUG -c Block.cpp -I .

Board.o: Board.h Board.cpp Block.o
	g++ -Wall -std=c++11 -DEBUG -c Board.cpp Block.o -I .


Tet.o: Tet.h Tet.cpp 
	g++ -Wall -std=c++11 -DEBUG -c Tet.cpp
	