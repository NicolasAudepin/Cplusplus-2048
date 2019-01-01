
#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>
#include "Board.h"
#include "Block.h"

using namespace std;

Board::Board(){

    change==true;

    nbToChar[0]='.';
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
        values[i]='.';
        freeSpace.push_back(i);
    }

    srand(time(nullptr));

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
        values[i]='.';
        freeSpace.push_back(i);
    }

};

void Board::showBoard(){
    for (int d=0;d<16;d++){
        values[d]='.';
    }

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
            rotate(2);
            fall();
            mergeAll();
            rotate(2);
            
                        
        break;
        case 'q':
            cout << "\nLEFT\n";

            rotate(1);
            fall();
            mergeAll();
            rotate(-1);
                        
        break;
        case 's':
            cout << "\nDOWN\n";

            fall();
            mergeAll();
            
                        
        break;
        case 'd':
            cout << "\nRIGHT\n";
            rotate(-1);
            fall();
            mergeAll();
            rotate(1);
                        
        break;
    } 
    //showBlocks();
    //showBoard();
    recountFreeSpace();
    spawnNewRandomBlock();
}

void Board::rotate(int nbPiSur2){
    for(size_t i(0);i<blocks.size();i++){
        if(nbPiSur2==1){
            int x = blocks[i].getX();
            blocks[i].setX(blocks[i].getY());
            blocks[i].setY(3-x);

        }
        if(nbPiSur2==-1){
            int x = blocks[i].getX();
            blocks[i].setX(3-blocks[i].getY());
            blocks[i].setY(x);

        }
        if(nbPiSur2==2){
            blocks[i].setX(3-blocks[i].getX());
            blocks[i].setY(3-blocks[i].getY());

        }
    }
}

struct compareBlock{
    inline bool operator() (Block& b1, Block& b2){
        return (b1.getY() > b2.getY());
    }
};

void Board::fall(){
    change=false;

    std::sort(blocks.begin(),blocks.end(),compareBlock());

    for(unsigned int i(0);i<blocks.size();i++){
        bool falling(true);

        while(falling){
            if (blocks[i].getY()==3){
                falling = false;
            }
            for(unsigned int j(0);j<blocks.size();j++){
                if(blocks[j].getX()==blocks[i].getX()){
                    if((blocks[j].getY()==blocks[i].getY()+1)&&(blocks[j].getVal() != blocks[i].getVal())){
                        falling = false;
                    }

                }
            }
            int fusionBelow=0;

            for (unsigned int j(0);j<blocks.size();j++){
                if((blocks[j].getY()==blocks[i].getY()+1) && (blocks[j].getX()==blocks[i].getX())){
                    fusionBelow++;
                }
            if (fusionBelow>1){
                falling=false;
            }

            }

            if (falling){
                change=true;
                //cout<<"\nFALLING\n";
                //showBoard();
                //cout<< blocks.size();
                blocks[i].setY(blocks[i].getY()+1);
                //cout<< blocks.size();
                
            }

            //showBoard();
        }
        
    }
    

}

void Board::showBlocks(){
    cout<<"\n";
    for(size_t j(0);j<blocks.size();j++){
        cout<<blocks[j].getX()<< blocks[j].getY()<<" ";
    }
}


void Board::mergeAll(){
    size_t i(0);
    while(i<blocks.size()){
        //cout<<"\nwhile";
        size_t j(0);
        while(j<blocks.size()){
            if(i!=j){
                if ((blocks[i].getX()==blocks[j].getX())
                &&(blocks[i].getY()==blocks[j].getY())
                &&(blocks[i].getVal()==blocks[j].getVal())){
                    //cout <<"\nSUM";
                    blocks[i].setVal(blocks[i].getVal()*2);
                    blocks.erase(blocks.begin()+j);
                }
            }
            
            j++;
            
        }
        i++;
    }

}

void Board::recountFreeSpace(){
    freeSpace.clear();
    for(size_t i(0); i<16;i++){
        bool occuped(false);
        for(size_t j(0);j<blocks.size();j++){
            unsigned int pos;
            pos = blocks[j].getX()+blocks[j].getY()*4;
            if(i==pos){
                occuped = true;
            }
            
        }
        if (occuped ==false){
            freeSpace.push_back(i);
        }

    }

}

void Board::spawnNewRandomBlock(){
    if(freeSpace.empty()&& (change==false)){
        cout<< "GAME OVER";
    }

    else{
        if (change){

            int randomN = rand()%freeSpace.size();
            int pos = freeSpace[randomN];
            freeSpace.erase(freeSpace.begin()+randomN);
            Block b = Block(pos%4, pos/4);
            blocks.push_back(b);

        }

        

    }
}