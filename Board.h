#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <map>
#include <unordered_set>
#include "Block.h"



class Board{

    public:

    void showBlocks();
    void spawnNewRandomBlock();
    void showBoard();
    void move(char direction);
    void initialize();

    Board();
    ~Board();

    
    private:
    bool change; 
    void rotate(int nbPiSur2);
    void fall();
    void mergeAll();
    void recountFreeSpace();
    void mergeBlocs(Block a, Block b);    
    

    std::vector<int> freeSpace;
    std::map<int,char> nbToChar;
    std::vector<Block> blocks;
    Block tb;  
    char values[16]; 

};


#endif   