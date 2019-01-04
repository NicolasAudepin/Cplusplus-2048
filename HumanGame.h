#ifndef HUMANGAME_H
#define HUMANGAME_H
#include "Board.h"

class HumanGame{

    

    public:

    HumanGame();
    ~HumanGame();

    void play();
    void reciveinput(char input);

    private:
    Board myBoard;
    





};

#endif