#ifndef GUI_H
#define GUI_H
#include "HumanGame.h"
#include "Board.h"
#include <string>

class GUI{
    public:
    GUI();
    ~GUI();
    void start();

    private:

    HumanGame humanGame;

    std::string helpstring;

    void startHumanGame();
    void startBotGame();

    




};

#endif