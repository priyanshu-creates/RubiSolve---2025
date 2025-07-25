#ifndef IDDFS_H
#define IDDFS_H

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class IDDFS{

    private:
    vector<int> moves;
    bool solved;
    void dfs(T state, int rem){
        solved |= state.isSolved();
        if(solved or rem<=0) return;
        for(int i = 0; i < 18; i++){
            moves.push_back(i);
            T temp = state;
            temp.performMove(i);
            dfs(temp, rem-1);
            if(solved) break;
            moves.pop_back();
        }
    }

    public:
    T startCube;
    IDDFS(T cube){
        startCube = cube;
        cout << "original cube: \n";
        startCube.printCube();
    }

    vector<int> solve(int depth){
        solved = false;
        moves.clear();
        for(int i = 1; i <= depth; i++){
            dfs(startCube, i);
            if(solved) break;
        }
        cout << "solved: " << solved << '\n';
        if(solved) return moves;
        else return vector<int> {-1};
    }
};

#endif
