#include"HumanGame.h"
#include "iostream"
#include "string"

using namespace std;

HumanGame::HumanGame(){
    myBoard=Board();
}

HumanGame::~HumanGame(){
    cout << "\nend human game";
}


void HumanGame::play(){
    myBoard.initialize();
    myBoard.spawnNewRandomBlock();
}

void HumanGame::reciveinput(char input){
    myBoard.move(input);
}