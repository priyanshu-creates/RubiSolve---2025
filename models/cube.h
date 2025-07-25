#ifndef CUBE_H
#define CUBE_H

using namespace std;
#include<bits/stdc++.h>

class Cube{
    public:
    enum COLOR{
        WHITE, BLUE, RED, YELLOW, GREEN, ORANGE
    };

    enum FACE{
        UP, DOWN, FRONT, BACK, LEFT, RIGHT
    };

    virtual int getColorIndex(COLOR color);
    virtual char getColorLetter(COLOR color);
    virtual COLOR getIndexColor(int index);

    virtual int getFaceIndex(FACE face);
    virtual FACE getIndexFace(int index);

    virtual void performMove(int index);
    virtual void reverseMove(int index);
    virtual string getMoveStr(int index);

    //rotations
    virtual void l() = 0;
    virtual void lp() = 0;
    virtual void l2() = 0;

    virtual void r() = 0;
    virtual void rp() = 0;
    virtual void r2() = 0;

    virtual void f() = 0;
    virtual void fp() = 0;
    virtual void f2() = 0;

    virtual void b() = 0;
    virtual void bp() = 0;
    virtual void b2() = 0;

    virtual void u() = 0;
    virtual void up() = 0;
    virtual void u2() = 0;

    virtual void d() = 0;
    virtual void dp() = 0;
    virtual void d2() = 0;

    //basics
    virtual COLOR getColor(FACE face, int row, int col) = 0;
    virtual void printCube();
    virtual vector<int> shuffle(int moves);
    virtual bool isSolved();

    //solve helpers
    virtual vector<COLOR> getCornerColors(int physicalIndex);
    virtual uint8_t getColorValue(COLOR color);
    virtual uint8_t getCornerIndex(int physicalIndex);//
    virtual uint8_t getCornerOrientation(int physicalIndex);
};

#endif