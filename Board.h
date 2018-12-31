#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <map>
#include <unordered_set>
#include "Block.h"



class Board{

    public:



    void showBoard();
    void move(char direction);
    void initialize();

    Board();
    ~Board();

    
    private:
    void fall();
    void spawnNewRandomBlock();
    void placeBlock(Block b, int pos);
    void mergeBlocs(Block a, Block b);    
    

    std::vector<int> freeSpace;
    std::map<int,char> nbToChar;
    std::vector<Block> blocks;
    Block tb;  
    char values[16]; 

};


#endif   