#include "cube.h"
using namespace std;
#include <bits/stdc++.h>
#define ull unsigned long long int

class Cubebit: public Cube{

    public:
    void printBits(ull x){
        for(int i = 0; i < 63; i++){
            if(i%8==0) cout << ' ';
            cout << ((x>>i)&1);
        }
        cout << '\n';
    }
    //private:
    int getLog(ull x){
        x&=255;
        switch(x){
            case 1: return 0;
            case 2: return 1;
            case 4: return 2;
            case 8: return 3;
            case 16: return 4;
            case 32: return 5;
            default: return -1;
        }
    }

    int getByteIndex(int row, int col){
        if(row==0) return col;
        if(row==2) return 6-col;
        if(row==1) {
            switch(col){
                case 0: return 7;
                case 1: return -1; //-1 means color same as face index
                case 2: return 3;
            }
        }
    }

    void swapbyte(ull& cubie, ull& temp, int row, int col){
        ull shift = getByteIndex(row, col)*8;
        ull tt = temp&255LL;
        temp = cubie>>shift;
        ull mask = ~(255LL<<shift);
        cubie&=mask;
        cubie|=(tt<<shift);
        // printBits(temp), printBits(tt), printBits(mask), printBits(cubie);
        // cout << shift << '\n';
    }

    void reset(){
        for(int i = 0; i < 6; i++){
            cube[i] = 0;
            for(int j = 0; j < 8; j++) {
                cube[i] = (cube[i]<<8)|(1<<i);
            }
        }
    }

    ull cube[6];

    //public:
    Cubebit(){
        reset();
    }
    COLOR getColor(FACE face, int row, int col) override {
        int findex = getFaceIndex(face);
        if(row==1 and col==1) return getIndexColor(findex);
        ull byt = cube[findex]>>(8*getByteIndex(row, col));
        return getIndexColor(getLog(byt));
    }
    
    void rotateFace(int findex){
        cube[findex] = (cube[findex]<<8LL) | (cube[findex]>>56LL);
        cube[findex] = (cube[findex]<<8LL) | (cube[findex]>>56LL);
    }

    void l() override{
        rotateFace(getFaceIndex(LEFT));
        int uid = getFaceIndex(UP), fid = getFaceIndex(FRONT), did = getFaceIndex(DOWN), bid = getFaceIndex(BACK);
        ull temp[3] = {cube[uid]>>(getByteIndex(0, 0)*8), cube[uid]>>(getByteIndex(1, 0)*8), cube[uid]>>(getByteIndex(2, 0)*8)};
        for(int i = 0; i < 3; i++) swapbyte(cube[fid], temp[i], i, 0);
        for(int i = 0; i < 3; i++) swapbyte(cube[did], temp[i], i, 0);
        for(int i = 0; i < 3; i++) swapbyte(cube[bid], temp[i], 2-i, 2);
        for(int i = 0; i < 3; i++) swapbyte(cube[uid], temp[i], i, 0);
    }
    void l2() override{l(); l();}
    void lp() override{l(); l(); l();}

    void r() override{
        rotateFace(getFaceIndex(RIGHT));
        int uid = getFaceIndex(UP), fid = getFaceIndex(FRONT), did = getFaceIndex(DOWN), bid = getFaceIndex(BACK);
        ull temp[3] = {cube[uid]>>(getByteIndex(0, 2)*8), cube[uid]>>(getByteIndex(1, 2)*8), cube[uid]>>(getByteIndex(2, 2)*8)};
        for(int i = 0; i < 3; i++) swapbyte(cube[bid], temp[i], 2-i, 0);
        for(int i = 0; i < 3; i++) swapbyte(cube[did], temp[i], i, 2);
        for(int i = 0; i < 3; i++) swapbyte(cube[fid], temp[i], i, 2);
        for(int i = 0; i < 3; i++) swapbyte(cube[uid], temp[i], i, 2);
    }
    void r2() override{r(); r();}
    void rp() override{r(); r(); r();}

    void f() override{
        rotateFace(getFaceIndex(FRONT));
        int uid = getFaceIndex(UP), did = getFaceIndex(DOWN), lid = getFaceIndex(LEFT), rid = getFaceIndex(RIGHT);
        ull temp[3] = {cube[uid]>>(getByteIndex(2, 0)*8), cube[uid]>>(getByteIndex(2, 1)*8), cube[uid]>>(getByteIndex(2,2)*8)};
        for(int i = 0; i < 3; i++) swapbyte(cube[rid], temp[i], i, 0);
        for(int i = 0; i < 3; i++) swapbyte(cube[did], temp[i], 0, 2-i);
        for(int i = 0; i < 3; i++) swapbyte(cube[lid], temp[i], 2-i, 2);
        for(int i = 0; i < 3; i++) swapbyte(cube[uid], temp[i], 2, i);
    }
    void f2() override{f(); f();}
    void fp() override{f(); f(); f();}

    void d() override{
        rotateFace(getFaceIndex(DOWN));
        int fid = getFaceIndex(FRONT), bid = getFaceIndex(BACK), lid = getFaceIndex(LEFT), rid = getFaceIndex(RIGHT);
        ull temp[3] = {cube[fid]>>(getByteIndex(2, 0)*8), cube[fid]>>(getByteIndex(2, 1)*8), cube[fid]>>(getByteIndex(2, 2)*8)};
        for(int i = 0; i < 3; i++) swapbyte(cube[rid], temp[i], 2, i);
        for(int i = 0; i < 3; i++) swapbyte(cube[bid], temp[i], 2, i);
        for(int i = 0; i < 3; i++) swapbyte(cube[lid], temp[i], 2, i);
        for(int i = 0; i < 3; i++) swapbyte(cube[fid], temp[i], 2, i);
    }
    void d2() override{d(); d();}
    void dp() override{d(); d(); d();}

    void u() override{
        rotateFace(getFaceIndex(UP));
        int fid = getFaceIndex(FRONT), bid = getFaceIndex(BACK), lid = getFaceIndex(LEFT), rid = getFaceIndex(RIGHT);
        ull temp[3] = {cube[fid]>>(getByteIndex(0, 0)*8), cube[fid]>>(getByteIndex(0, 1)*8), cube[fid]>>(getByteIndex(0, 2)*8)};
        for(int i = 0; i < 3; i++) swapbyte(cube[lid], temp[i], 0, i);
        for(int i = 0; i < 3; i++) swapbyte(cube[bid], temp[i], 0, i);
        for(int i = 0; i < 3; i++) swapbyte(cube[rid], temp[i], 0, i);
        for(int i = 0; i < 3; i++) swapbyte(cube[fid], temp[i], 0, i);
    }
    void u2() override{u(); u();}
    void up() override{u(); u(); u();}

    void b() override{
        rotateFace(getFaceIndex(BACK));
        int uid = getFaceIndex(UP), did = getFaceIndex(DOWN), lid = getFaceIndex(LEFT), rid = getFaceIndex(RIGHT);
        ull temp[3] = {cube[uid]>>(getByteIndex(0,0)*8), cube[uid]>>(getByteIndex(0, 1)*8), cube[uid]>>(getByteIndex(0, 2))*8};
        for(int i = 0; i < 3; i++) swapbyte(cube[lid], temp[i], 2-i, 0);
        for(int i = 0; i < 3; i++) swapbyte(cube[did], temp[i], 2, 2-i);
        for(int i = 0; i < 3; i++) swapbyte(cube[rid], temp[i], i, 2);
        for(int i = 0; i < 3; i++) swapbyte(cube[uid], temp[i], 0, i);
    }
    void b2() override{b(); b();}
    void bp() override{b(); b(); b();}

    ////////////////////////////////////
    ////////// Overrides and Hash
    ///////////////////////////////////
    bool operator == (const Cubebit& a) const {
        for(int i = 0; i < 6; i++) if(a.cube[i]!=cube[i]) return false;
        return true;
    }

    void operator = (const Cubebit& a){
        for(int i = 0; i < 6; i++) cube[i]=a.cube[i];
    }
};

struct Hasherbit{
    size_t operator()(const Cubebit& a) const{
        string s;
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 8; j++){
                s += char((a.cube[i]>>(8*j))&255LL);       
            }
        }
        return hash<string>()(s);
    }
};
