
#include<string>
#include<iostream>
#include "Block.h"
#include"Board.h"
#include "GUI.h"
#include "HumanGame.h"

using namespace std;

int main(void){

    GUI gui;

    gui.start();

    Board *bp;
    bp= new Board();
    bool running(true);
    (*bp).initialize();
    (*bp).spawnNewRandomBlock();
    (*bp).showBoard();

    while(running){
        char input;
        cin >> input;
        (*bp).move(input);
        (*bp).showBoard();



        

    }
    
    
    delete bp;
    cout << "\n\nGAME OVER\n";
    return 0;
}