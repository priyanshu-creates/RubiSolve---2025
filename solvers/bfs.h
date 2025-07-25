#ifndef BFS_H
#define BFS_H

#include <bits/stdc++.h>
using namespace std;

template<typename T, typename H>
class BFS{
    private:
    H hasher;
    T req;
    unordered_map<T, bool, H> vis;
    unordered_map<T, int, H> parMove;
    unordered_map<T, int, H> len;
    void bfs(T state, int depth){
        queue<T> q; q.push(state); len[state] = 0; parMove[state] = -1;
        while(!q.empty()){
            T cur = q.front(); q.pop();
            if(vis[cur] or len[cur]>=depth) continue;
            vis[cur] = true;
            if(cur==req) return;

            for(int i = 0; i < 18; i++){
                T temp = cur; temp.performMove(i);
                if(len.find(temp)!=len.end() and len[temp] <= len[cur]+1) continue;
                parMove[temp] = i; len[temp] = len[cur]+1;
                q.push(temp);
            }
        }
    }

    public:
    T startCube;
    BFS(T cube){
        startCube = cube;
        cout << "original cube: \n";
        startCube.printCube();
    }

    vector<int> solve(int depth){
        vis.clear(), parMove.clear(), len.clear();
        req = T();
        bfs(startCube, depth);

        if(vis.find(req) == vis.end()) {cout << "solved: " << 0 << '\n'; return vector<int> {-1};}
        cout << "solved: 1\n"; // now back track to the start state
        vector<int> moves;  
        while(parMove[req]!=-1){
            int move = parMove[req];
            moves.push_back(move);
            req.reverseMove(move);
        }
        reverse(moves.begin(), moves.end());
        return moves;
    }
};

#endif
