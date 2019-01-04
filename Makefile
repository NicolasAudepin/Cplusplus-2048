main: main.cc Board.o Block.o GUI.o HumanGame.o
	g++ -DEBUG -o main main.cc Board.o Block.o GUI.o HumanGame.o -I .


Block.o: Block.h Block.cpp
	g++ -Wall -std=c++11 -DEBUG -c Block.cpp -I .

Board.o: Board.h Board.cpp Block.o
	g++ -Wall -std=c++11 -DEBUG -c Board.cpp Block.o -I .


GUI.o: GUI.h GUI.cpp HumanGame.o
	g++ -Wall -std=c++11 -DEBUG -c GUI.cpp HumanGame.o -I.

HumanGame.o: HumanGame.h HumanGame.cpp Board.o
	g++ -Wall -std=c++11 -DEBUG -c HumanGame.cpp Board.o -I. 