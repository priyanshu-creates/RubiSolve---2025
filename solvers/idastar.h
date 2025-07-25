#ifndef IDASTAR_H
#define IDASTAR_H

#include <bits/stdc++.h>
#include "../helpers/Cornerdb.h"
using namespace std;

template<typename T, typename H>
class IDASTAR{
    private:
    Cornerdb<T> hue = Cornerdb<T>();
    int getHeu(T state){
        int temp = (int) hue.get(state);
        //cout << temp << ' ';
        return temp;
    }

    struct cmpPQ{
        bool operator()(pair<int, T> const &a, pair<int, T> const &b) {return a.first > b.first;}
    };

    T req = T();
    bool solved = false;
    unordered_map<T, bool, H> vis;
    unordered_map<T, int, H> parMove;
    unordered_map<T, int, H> len;
    int dijkstra(T state, int lim){
        //init
        solved = false, vis.clear(), parMove.clear(), len.clear();
        priority_queue<pair<int, T>, vector<pair<int, T>>, cmpPQ> q; q.push(make_pair(0, state));
        len[state] = 0; parMove[state] = -1;
        int nextmini = 1e9;

        //solve
        while(!q.empty()){
            T cur = q.top().second; q.pop();
            if(vis[cur]) continue; vis[cur] = true;
            if(cur==req) {solved = true; return 1e9;}

            for(int i = 0; i < 18; i++){
                T temp = cur; temp.performMove(i);
                int estimate = getHeu(temp);
                int tot = estimate + len[cur] + 1;
                if(len.find(temp)!=len.end() and len[temp] <= tot) continue;
                if(tot > lim) nextmini = min(nextmini, tot);
                else parMove[temp] = i, len[temp] = len[cur]+1, q.push(make_pair(tot, temp));
            }
        }
        return nextmini;
    }

    public:
    T startCube;
    IDASTAR(T cube){
        startCube = cube;
        cout << "original cube: \n";
        startCube.printCube();
    }

    vector<int> solve(int depth){
        int bound = 1;
        while(bound <= depth){
            if(solved) break;
            bound = dijkstra(startCube, depth);
        }

        if(!solved) {cout << "solved: " << 0 << '\n'; return vector<int> {-1};}
        cout << "solved: 1\n";
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
