#include <iostream>
#include<string>
#include "GUI.h"
#include "HumanGame.h"

using namespace::std;


GUI::GUI(){
    //cout << "GUI created";
    helpstring ="\n ____________________________________ ";
    helpstring+="\n|2|4|8|16|32|64|128|256|512|1024|2048|";
    helpstring+="\n|_|_|_|__|__|__|___|___|___|____|____|";
    helpstring+="\n|A|B|C|D |E |F | G | H | I | J  | K  |";
    helpstring+="\n|_|_|_|__|__|__|___|___|___|____|____|\n";
}

void GUI::start(){
    cout<< "\n ____________________________________ "
        << "\n|    ___     ____      _     ____    |"
        << "\n|   |   |   |    |    / |   |    |   |"
        << "\n|     _/    |    |   /  |   |____|   |"
        << "\n|    /      |    |  |___|_  |    |   |"
        << "\n|   |____   |____|      |   |____|   |"
        << "\n|____________________________________|"
        << "\n|                                    |"
        << "\n|  H : START HUMAN GAME              |"
        << "\n|  B : START BOT                     |"
        << "\n|  X : QUIT GAME                     |"
        << "\n|  A : HELP                          |"
        << "\n|____________________________________|"
        << "\n";


    bool runing(true);
    bool gamePlaying(false);
    bool human(false);

    while(runing){
        cout <<"input ? : ";
        char input;
        cin >> input;

        switch(input){

            case 'h':
                if(gamePlaying==false){
                    cout<<"\nHuman\n";
                    gamePlaying=true;
                    human = true;
                    startHumanGame();
                }
                break;
            
            case 'b':
                if(gamePlaying==false){
                    cout<<"\nBot\n";
                    gamePlaying=true;
                    startBotGame();
                }
                break;
            
            case 'x':
                cout<<"\nExit\n";
                runing=false;
                break;
            
            case 'a':
                cout<<helpstring;
                break;
        }

        if(human && gamePlaying){
            //cout<<"\n input for game";
            switch(input){
                case 'z':
                case 'q':
                case 's':
                case 'd':
                    humanGame.reciveinput(input);
                    humanGame.showBoard();
            }
        }       


    }     
}

GUI::~GUI(){
    
}

void GUI::startHumanGame(){
    //class HumanGame;
    humanGame = HumanGame();

    humanGame.startGame();

}

void GUI::startBotGame(){

}