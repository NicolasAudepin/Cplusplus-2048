
#ifndef BLOC_H
#define BLOC_H

class Block {


    private:
    
    int x;
    int y;
    int val;
    

    public:

    Block();
    Block(int _x, int _y);
    ~Block();
    Block(int _x, int _y, int _val);


    int const getX();
    int const getY();
    int getVal();
    void setX(int _x);
    void setY(int _y);
    void setVal(int _val);


};


#endif