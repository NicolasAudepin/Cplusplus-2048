
#include <string>
#include <iostream>
#include <algorithm>
#include "Board.h"
#include "Block.h"

using namespace std;

Board::Board(){

    nbToChar[0]='0';
    nbToChar[2]='A';
    nbToChar[4]='B';
    nbToChar[8]='C';
    nbToChar[16]='D';
    nbToChar[32]='E';
    nbToChar[64]='F';
    nbToChar[128]='G';
    nbToChar[256]='H';
    nbToChar[512]='I';
    nbToChar[1024]='J';
    nbToChar[2048]='K';

    blocks.clear();
    
    for(int i = 0;i<16;i++){
        values[i]='0';
        freeSpace.push_back(i);
    }

    cout<<"Board built\n";
}

Board::~Board(){
    cout<<"Board Destroyed\n";
}

void Board::initialize(){
    cout<<"initializing board";
    blocks.clear();
    freeSpace.clear();
    
    for(int i = 0;i<16;i++){
        values[i]='0';
        freeSpace.push_back(i);
    }

};

void Board::showBoard(){


    //regard la liste des blocs et met leurs simboles dans values    
    for (size_t i=0;i<blocks.size();i++){
        int pos;
        pos = blocks[i].getX()+blocks[i].getY()*4;
        values[pos]=nbToChar[(blocks[i].getVal())];        
    }

    cout<<"\n";
    cout<< values[0]<<" "<< values[1]<<" "<< values[2]<<" "<< values[3]<<" ";
    cout<<"\n";
    cout<< values[4]<<" "<< values[5]<<" "<< values[6]<<" "<< values[7]<<" ";
    cout<<"\n";
    cout<< values[8]<<" "<< values[9]<<" "<< values[10]<<" "<< values[11]<<" ";
    cout<<"\n";
    cout<< values[12]<<" "<< values[13]<<" "<< values[14]<<" "<< values[15]<<" ";
    cout<<"\n";



}

void Board::move(char direction){ 
    switch(direction){
        case 'z':
            cout << "\nUP\n";
                        
        break;
        case 'q':
            cout << "\nLEFT\n";
                        
        break;
        case 's':
            cout << "\nDOWN\n";

            fall();
                        
        break;
        case 'd':
            cout << "\nRIGHT\n";
                        
        break;
    } 
    spawnNewRandomBlock();
}

struct compareBlock{
    inline bool operator() (Block& b1, Block& b2){
        return (b1.getY() < b2.getY());
    }
};

void Board::fall(){

    std::sort(blocks.begin(),blocks.end(),compareBlock());

    for(unsigned int i(0);i<blocks.size();i++){
        bool falling(true);
        while(falling){
            if (blocks[i].getY()==3){
                falling = false;
            }
            for 
        }
        
    }

}



void Board::spawnNewRandomBlock(){
    if(freeSpace.empty()){
        cout<< "GAME OVER";
    }

    else{

        int randomN = 0;
        int pos = freeSpace[randomN];
        freeSpace.erase(freeSpace.begin()+randomN);
        Block b = Block(pos%4, pos/4);
        blocks.push_back(b);


    }
}