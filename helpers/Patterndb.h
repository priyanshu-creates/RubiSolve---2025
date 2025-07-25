#ifndef PATTDB_H
#define PATTDB_H
#include "nibble.h"
#include "math.h"

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Patterndb{
    private:

    public:
    Nibble arr;
    void init(int tot, int def = 0){
        arr = Nibble(tot, def);
    }
    int save(string name){
        return arr.save(name);
    }
    int load(string name){
        return arr.load(name);
    }

    virtual uint64_t getIndex(T state) = 0;

    uint8_t get(T state){
        uint64_t idx = getIndex(state);
        return arr.get(idx);
    }
    void set(uint64_t idx, uint8_t val){
        arr.set(idx, val);
    }
};

#endif
