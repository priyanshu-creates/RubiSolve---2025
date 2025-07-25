#include "cube.h"
using namespace std;
#include <bits/stdc++.h>

class Cube3d: public Cube{

    public:
    int cube[6][3][3];
    Cube3d(){
        for(int i = 0; i < 6; i++) {for(int j = 0; j < 3; j++) for(int k = 0; k < 3; k++) cube[i][j][k] = i;}
    }
    COLOR getColor(FACE face, int row, int col) override {return getIndexColor(cube[getFaceIndex(face)][row][col]);}
    
    void rotateFace(int findex){
        int temp[3][3];
        for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) temp[i][j] = cube[findex][i][j];
        for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) cube[findex][i][j] = temp[2-j][i];
    }

    void l() override{
        rotateFace(getFaceIndex(LEFT));
        int uid = getFaceIndex(UP), fid = getFaceIndex(FRONT), did = getFaceIndex(DOWN), bid = getFaceIndex(BACK);
        int temp[3] = {cube[uid][0][0], cube[uid][1][0], cube[uid][2][0]};
        for(int i = 0; i < 3; i++) swap(cube[fid][i][0], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[did][i][0], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[bid][2-i][2], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[uid][i][0], temp[i]);
    }
    void l2() override{l(); l();}
    void lp() override{l(); l(); l();}

    void r() override{
        rotateFace(getFaceIndex(RIGHT));
        int uid = getFaceIndex(UP), fid = getFaceIndex(FRONT), did = getFaceIndex(DOWN), bid = getFaceIndex(BACK);
        int temp[3] = {cube[uid][0][2], cube[uid][1][2], cube[uid][2][2]};
        for(int i = 0; i < 3; i++) swap(cube[bid][2-i][0], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[did][i][2], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[fid][i][2], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[uid][i][2], temp[i]);
    }
    void r2() override{r(); r();}
    void rp() override{r(); r(); r();}

    void f() override{
        rotateFace(getFaceIndex(FRONT));
        int uid = getFaceIndex(UP), did = getFaceIndex(DOWN), lid = getFaceIndex(LEFT), rid = getFaceIndex(RIGHT);
        int temp[3] = {cube[uid][2][0], cube[uid][2][1], cube[uid][2][2]};
        for(int i = 0; i < 3; i++) swap(cube[rid][i][0], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[did][0][2-i], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[lid][2-i][2], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[uid][2][i], temp[i]);
    }
    void f2() override{f(); f();}
    void fp() override{f(); f(); f();}

    void d() override{
        rotateFace(getFaceIndex(DOWN));
        int fid = getFaceIndex(FRONT), bid = getFaceIndex(BACK), lid = getFaceIndex(LEFT), rid = getFaceIndex(RIGHT);
        int temp[3] = {cube[fid][2][0], cube[fid][2][1], cube[fid][2][2]};
        for(int i = 0; i < 3; i++) swap(cube[rid][2][i], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[bid][2][i], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[lid][2][i], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[fid][2][i], temp[i]);
    }
    void d2() override{d(); d();}
    void dp() override{d(); d(); d();}

    void u() override{
        rotateFace(getFaceIndex(UP));
        int fid = getFaceIndex(FRONT), bid = getFaceIndex(BACK), lid = getFaceIndex(LEFT), rid = getFaceIndex(RIGHT);
        int temp[3] = {cube[fid][0][0], cube[fid][0][1], cube[fid][0][2]};
        for(int i = 0; i < 3; i++) swap(cube[lid][0][i], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[bid][0][i], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[rid][0][i], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[fid][0][i], temp[i]);
    }
    void u2() override{u(); u();}
    void up() override{u(); u(); u();}

    void b() override{
        rotateFace(getFaceIndex(BACK));
        int uid = getFaceIndex(UP), did = getFaceIndex(DOWN), lid = getFaceIndex(LEFT), rid = getFaceIndex(RIGHT);
        int temp[3] = {cube[uid][0][0], cube[uid][0][1], cube[uid][0][2]};
        for(int i = 0; i < 3; i++) swap(cube[lid][2-i][0], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[did][2][2-i], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[rid][i][2], temp[i]);
        for(int i = 0; i < 3; i++) swap(cube[uid][0][i], temp[i]);
    }
    void b2() override{b(); b();}
    void bp() override{b(); b(); b();}

    ////////////////////////////////////
    ////////// Overrides and Hash
    ///////////////////////////////////
    bool operator == (const Cube3d& a) const {
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++) if(a.cube[i][j][k]!=cube[i][j][k]) return false;
            }
        }
        return true;
    }

    void operator = (const Cube3d& a) {
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++) cube[i][j][k]=a.cube[i][j][k];
            }
        }
    }
};

struct Hasher3d{
    size_t operator()(const Cube3d& a) const {
        string s; for(int i = 0; i < 6; i++){
            for(int j = 0; j < 3; j++) for(int k = 0; k < 3; k++) s+=char(a.cube[i][j][k]);
        }
        return hash<string>()(s);
    }
};