#ifndef HUMANGAME_H
#define HUMANGAME_H
#include "Board.h"
#include <vector>
class HumanGame{

    

    public:

    HumanGame();
    ~HumanGame();

    void startGame();
    void reciveinput(char input);
    void getBoardList();
    void showBoard();

    private:
    Board myBoard;
    std::vector<char> valueList;






};

#endif