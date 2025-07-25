#include "cube.h"
using namespace std;
#include <bits/stdc++.h>

class Cube1d: public Cube{
    public:
    int cube[54];
    Cube1d(){
        for(int i = 0; i < 6; i++) {for(int j = 0; j < 9; j++) cube[9*i+j] = i;}
    }
    COLOR getColor(FACE face, int row, int col) override {return getIndexColor(cube[9*getFaceIndex(face)+  3*row + col]);}
    
    /////////////////////////////////////////////////
    //to be done from here..................
    /////////////////////////////////////////////////
    void rotateFace(int findex){
        int cor[4] = {2, 8, 6, 0}; int temp = cube[9*findex];
        for(int i = 0; i < 4; i++) swap(temp, cube[9*findex+cor[i]]);
        int edg[4] = {5, 7, 3, 1}; temp = cube[9*findex+1];
        for(int i = 0; i < 4; i++) swap(temp, cube[9*findex+edg[i]]);
    }

    void l() override{
        rotateFace(getFaceIndex(LEFT));
        int uid = 9*getFaceIndex(UP), fid = 9*getFaceIndex(FRONT), did = 9*getFaceIndex(DOWN), bid = 9*getFaceIndex(BACK);
        int temp[3] = {cube[uid+ 3*0 + 0], cube[uid + 3*1 + 0], cube[uid + 3*2 + 0]};
        for(int i = 0; i < 3; i++) swap(cube[fid + 3*i + 0], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[did + 3*i + 0], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[bid + 3*(2-i) + 2], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[uid + 3*i + 0], temp[i]);
    }
    void l2() override{l(); l();}
    void lp() override{l(); l(); l();}

    void r() override{
        rotateFace(getFaceIndex(RIGHT));
        int uid = 9*getFaceIndex(UP), fid = 9*getFaceIndex(FRONT), did = 9*getFaceIndex(DOWN), bid = 9*getFaceIndex(BACK);
        int temp[3] = {cube[uid + 3*0 + 2], cube[uid + 3*1 + 2], cube[uid + 3*2 + 2]};
        for(int i = 0; i < 3; i++) swap(cube[bid + 3*(2-i) + 0], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[did + 3*i + 2], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[fid + 3*i + 2], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[uid + 3*i + 2], temp[i]);
    }
    void r2() override{r(); r();}
    void rp() override{r(); r(); r();}

    void f() override{
        rotateFace(getFaceIndex(FRONT));
        int uid = 9*getFaceIndex(UP), did = 9*getFaceIndex(DOWN), lid = 9*getFaceIndex(LEFT), rid = 9*getFaceIndex(RIGHT);
        int temp[3] = {cube[uid + 3*2 + 0], cube[uid + 3*2 + 1], cube[uid + 3*2 + 2]};
        for(int i = 0; i < 3; i++) swap(cube[rid + 3*i + 0], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[did + 3*0 + (2-i)], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[lid + 3*(2-i) + 2], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[uid + 3*2 + i], temp[i]);
    }
    void f2() override{f(); f();}
    void fp() override{f(); f(); f();}

    void d() override{
        rotateFace(getFaceIndex(DOWN));
        int fid = 9*getFaceIndex(FRONT), bid = 9*getFaceIndex(BACK), lid = 9*getFaceIndex(LEFT), rid = 9*getFaceIndex(RIGHT);
        int temp[3] = {cube[fid + 3*2 + 0], cube[fid + 3*2 + 1], cube[fid + 3*2 + 2]};
        for(int i = 0; i < 3; i++) swap(cube[rid + 3*2 + i], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[bid + 3*2 + i], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[lid + 3*2 + i], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[fid + 3*2 + i], temp[i]);
    }
    void d2() override{d(); d();}
    void dp() override{d(); d(); d();}

    void u() override{
        rotateFace(getFaceIndex(UP));
        int fid = 9*getFaceIndex(FRONT), bid = 9*getFaceIndex(BACK), lid = 9*getFaceIndex(LEFT), rid = 9*getFaceIndex(RIGHT);
        int temp[3] = {cube[fid + 3*0 + 0], cube[fid + 3*0 + 1], cube[fid + 3*0 + 2]};
        for(int i = 0; i < 3; i++) swap(cube[lid + 3*0 + i], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[bid + 3*0 + i], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[rid + 3*0 + i], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[fid + 3*0 + i], temp[i]);
    }
    void u2() override{u(); u();}
    void up() override{u(); u(); u();}

    void b() override{
        rotateFace(getFaceIndex(BACK));
        int uid = 9*getFaceIndex(UP), did = 9*getFaceIndex(DOWN), lid = 9*getFaceIndex(LEFT), rid = 9*getFaceIndex(RIGHT);
        int temp[3] = {cube[uid + 3*0 + 0], cube[uid + 3*0 + 1], cube[uid + 3*0 + 2]};
        for(int i = 0; i < 3; i++) swap(cube[lid + 3*(2-i) + 0], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[did + 3*2 + (2-i)], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[rid + 3*i + 2], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[uid + 3*0 + i], temp[i]);
    }
    void b2() override{b(); b();}
    void bp() override{b(); b(); b();}

    ////////////////////////////////////
    ////////// Overrides and Hash
    ///////////////////////////////////
    bool operator == (const Cube1d& a) const {
        for(int i = 0; i < 54; i++) if(a.cube[i]!=cube[i]) return false;
        return true;
    }

    void operator = (const Cube1d& a){
        for(int i = 0; i < 54; i++) cube[i]=a.cube[i];
    }
};

struct Hasher1d{
    size_t operator() (const Cube1d& a) const {
        string s; for(int i = 0; i < 54; i++) s += char(a.cube[i]);
        return hash<string>()(s);
    }
};
