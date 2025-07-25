#ifndef CORNERDB_H
#define CORNERDB_H

#include <bits/stdc++.h>
#include "Patterndb.h"
#include "PermutationIndexer.h"

#define carr array<uint8_t, 8>
#define MAX_DEPTH 6

template<typename T>
class Cornerdb : public Patterndb<T>{
    public:
    string filename = "Cornerdb"+to_string(MAX_DEPTH);
    PermutationIndexer<8> indexer = PermutationIndexer<8>();
    carr getCornerArray(T state);
    void build();
    Cornerdb();
    uint64_t getIndex(T state) override{
        uint64_t idx = indexer.rank(getCornerArray(state))*2187;
        idx += state.getCornerOrientation(0)*729 +
                state.getCornerOrientation(1)*243 +
                state.getCornerOrientation(2)*81 +
                state.getCornerOrientation(3)*27 +
                state.getCornerOrientation(4)*9 +
                state.getCornerOrientation(5)*3 +
                state.getCornerOrientation(6);
        return idx;
    }
};

template<typename T>
Cornerdb<T>::Cornerdb(){
    //check if file present
    ifstream f((filename+".bin").c_str());
    bool exists = f.good();
    if(exists) {
        cout << "Found database! " << filename << '\n';
        this->load(filename);
        cout << "Loaded database successfully.\n";
    }else{
        //build if not present
        this->init(104857600, 0);
        build();
        cout << "Database built and saved" << '\n';
    }
};

template<typename T>
carr Cornerdb<T>::getCornerArray(T state){
    carr arr; for(int i = 0; i < 8; i++) arr[i] = state.getCornerIndex(i);
    return arr;
};

template<typename T>
void Cornerdb<T>::build() {
    cout << "Building Corner Database...\n";
    T cube = T();
    //max depth 
    unordered_map<uint64_t, pair<uint8_t, T>> dist;
    queue<T> q; q.push(cube); dist[getIndex(cube)] = {0, cube};
    while(!q.empty()){
        T state = q.front(); q.pop();
        uint64_t stateidx = getIndex(state);
        for(int i = 0; i < 18; i++){
            T temp = state;
            temp.performMove(i);
            uint64_t tempidx = getIndex(temp);
            if(dist.find(tempidx)!=dist.end()) continue;
            dist[tempidx] = make_pair(dist[stateidx].first+1, temp);
            if(dist[tempidx].first!=MAX_DEPTH) q.push(temp);
        }
    }

    //dist map has all the states upto MAX_DEPTH
    //Now, lets populate the patterndb and save it
    cout << dist.size() << '\n';
    for(auto& it: dist){
        this->set(it.first, it.second.first);
    }

    this->save("Cornerdb"+to_string(MAX_DEPTH));
}

#endif
