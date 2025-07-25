#include <bits/stdc++.h>

//solvers
#include "solvers/dfs.h"
#include "solvers/bfs.h"
#include "solvers/iddfs.h"  
#include "solvers/idastar.h"

//cube models
#include "models/cube3d.h"
#include "models/cube1d.h"
#include "models/cubebit.h"

template <typename T, typename H>
void solve(){
    T cube = T();
    int shuffleNum = 0; cout << "Enter number of shuffle moves: \n"; cin>>shuffleNum;

    vector<int> shuffle = cube.shuffle(shuffleNum);
    for(auto it: shuffle) cout << cube.getMoveStr(it) << ' '; cout << '\n';
    int searchDepth = 1; cout << "Enter max search depth: \n"; cin>>searchDepth;

    H algo = H(cube);
    vector<int> moves = algo.solve(searchDepth);
    cout << "Moves: " << "(" << moves.size() << "):";
    for(auto it: moves) cout << cube.getMoveStr(it) << ' '; cout << '\n';
}

signed main(){
    int cubetype = 0;
    while(1){
        cout << "Choose cube model to use:\n1. Cube3d\n2. Cube1d\n3. Cubebit\n";
        cin>>cubetype;
        if(cubetype < 1 or cubetype > 3) {cout << "Choose between 1 and 3\n"; continue;}
        break;
    }

    int algoidx = 0;
    while(1){
        cout << "Choose Algo to solve the cube:\n";
        cout << "1. DFS\n2. BFS\n3. IDDFS\n4. IDASTAR\n";
        cin>>algoidx;
        if(algoidx < 1 or algoidx > 4){cout << "Choose between 1 and 4\n"; continue;}
        break;
    }

    if(cubetype==1){
        switch(algoidx){
            case 1: {
                solve<Cube3d, DFS<Cube3d>>();
                break;
            }
            case 2: {
                solve<Cube3d, BFS<Cube3d, Hasher3d>>();
                break;
            }
            case 3: {
                solve<Cube3d, IDDFS<Cube3d>>();
                break;
            }
            case 4:{
                solve<Cube3d, IDASTAR<Cube3d, Hasher3d>>();
                break;
            }
        }
    }else if(cubetype==2){
        switch(algoidx){
            case 1: {
                solve<Cube1d, DFS<Cube1d>>();
                break;
            }
            case 2: {
                solve<Cube1d, BFS<Cube1d, Hasher1d>>();
                break;
            }
            case 3: {
                solve<Cube1d, IDDFS<Cube1d>>();
                break;
            }
            case 4:{
                solve<Cube1d, IDASTAR<Cube1d, Hasher1d>>();
                break;
            }
        }
    }else if(cubetype==3){
        switch(algoidx){
            case 1: {
                solve<Cubebit, DFS<Cubebit>>();
                break;
            }
            case 2: {
                solve<Cubebit, BFS<Cubebit, Hasherbit>>();
                break;
            }
            case 3: {
                solve<Cubebit, IDDFS<Cubebit>>();
                break;
            }
            case 4:{
                solve<Cubebit, IDASTAR<Cubebit, Hasherbit>>();
                break;
            }
        }
    }
    
    return 0;
}
