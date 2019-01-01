
#include "Block.h"
#include <iostream>
#include <string>

using namespace std;

Block::Block(){
    x=0;
    y=0;
    val=2;
}

Block::Block(int _x, int _y){
    x=_x;
    y=_y;
    val=2;
    //cout<<"block created with xy";
    
}


Block::Block(int _x, int _y, int _val){
    x=_x;
    y=_y;
    val=_val;
    //cout<<"block created with xyVal";
    
}

Block::~Block(){
    //cout << "block destroyed";
}

int Block::getVal(){
    return val;
}

int const Block::getX(){
    return x;
}

int const Block::getY(){
    return y;
}

void Block::setVal(int _val){
    val=_val;
}

void Block::setX(int _x){
    x=_x;
}

void Block::setY(int _y){
    y=_y;
}