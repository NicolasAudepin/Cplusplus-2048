#include"HumanGame.h"
#include "iostream"
#include "string"
#include "vector"

using namespace std;

HumanGame::HumanGame(){
    myBoard=Board();
}

HumanGame::~HumanGame(){
    cout << "\nend human game";
}


void HumanGame::startGame(){
    //cout << "\nstart Hgame ";
    myBoard.initialize();
    myBoard.spawnNewRandomBlock();
}

void HumanGame::reciveinput(char input){
    //cout<<"\nhg recive input";
    myBoard.move(input);
    myBoard.spawnNewRandomBlock();
}

void HumanGame::getBoardList(){
    valueList =myBoard.getValues();

}

void HumanGame::showBoard(){
    //cout<<"\nshow";
    getBoardList();

    cout<<endl
    <<valueList[0]<<" "<<valueList[2]<<" "<<valueList[2]<<" "<<valueList[3]<<endl
    <<valueList[4]<<" "<<valueList[5]<<" "<<valueList[6]<<" "<<valueList[7]<<endl
    <<valueList[8]<<" "<<valueList[9]<<" "<<valueList[10]<<" "<<valueList[11]<<endl
    <<valueList[12]<<" "<<valueList[13]<<" "<<valueList[14]<<" "<<valueList[15]<<endl;
}
