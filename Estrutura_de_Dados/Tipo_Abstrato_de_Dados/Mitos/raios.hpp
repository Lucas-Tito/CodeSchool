#ifndef RAIOS_HPP
#define RAIOS_HPP

#include <bits/stdc++.h>
#include <vector>
#include<algorithm>

using namespace std;

struct quadrante{
    int x;
    int y;
};

class Raios{

    private:
    
    int cityLength, cityWidth;
    vector<quadrante> vec;
       
    public:
    
    Raios(int n, int m){ 
        
        cityLength = n;
        cityWidth = m;

    }

    void add(int x, int y){

    quadrante qToAdd;
    qToAdd.x = x;
    qToAdd.y = y;
    vec.push_back(qToAdd);
        
    }

    int mesmo_lugar(){
    
        int areInSamePlace = 0;        
    
        for(int k=0; k<vec.size()-1; k++){
            for(int i=1; i<vec.size();  i++)
                if((vec.at(k).x == vec.at(i).x && vec.at(k).y == vec.at(i).y) && k != i){
                    areInSamePlace = 1;
                    break;
                }
            if(areInSamePlace == 1)
                break;  //break pro primeiro for parar de incrementar se uma duplicata for achada
        }

        return areInSamePlace;
    }
};


#endif
