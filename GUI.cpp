#include <iostream>
#include<string>
#include "GUI.h"
#include "HumanGame.h"

using namespace::std;


GUI::GUI(){
    //cout << "GUI created";
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
        << "\n|____________________________________|"
        << "\n";


        bool runing(true);
        bool gamePlaying(false);

        while(runing){
            char input;
        cin >> input;

        switch(input){

            case 'h':
                if(gamePlaying==false){
                    cout<<"\nHuman\n";
                    gamePlaying=true;
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
        }


    }     
}

GUI::~GUI(){
    
}

void GUI::startHumanGame(){
    //class HumanGame;
    HumanGame hg;

    (hg).play();

}

void GUI::startBotGame(){

}