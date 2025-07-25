#ifndef NIBBLE_H
#define NIBBLE_H

#include<bits/stdc++.h>
using namespace std;

class Nibble{
    private:
    vector<uint8_t> a;

    public:
    Nibble(){}
    Nibble(int tot, int def = 0){
        a.resize(tot, def);
    }

    uint8_t get(uint64_t pos){
        uint8_t temp = a[pos/2];
        if(pos%2) return (temp>>4);
        else return (temp&15);
    }

    void set(uint64_t pos, uint8_t val){
        uint8_t& temp = a[pos/2];
        if(pos%2) temp = ((temp&15) | (val<<4));
        else temp = ((temp&(255-15)) | (val&15));
    }

    uint8_t size(){return a.size();}

    int save(string name){
        ofstream out(name+".bin", ios::binary);
        if(!out){
            cerr << "Unable to open file.....\n";
            return 1;
        }

        out.write(reinterpret_cast<const char *>(a.data()), a.size()*sizeof(uint8_t));
        out.close();
        cout << "Written successfully to: " << name + ".bin" << '\n';
        return 0;
    }

    int load(string name){
        ifstream in(name+".bin", ios::binary);
        if(!in){
            cerr << "Unable to open input file....\n"; return 1;
        }

        a.clear();
        in.seekg(0, ios::end);
        streampos size = in.tellg();
        in.seekg(0, ios::beg);
        a.resize(size);
        in.read(reinterpret_cast<char *>(a.data()), size);
        in.close();

        cout << "Loaded " + name + ".bin successfully" << '\n';
        return 0;
    }
};

#endif 
