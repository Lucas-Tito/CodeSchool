#ifndef LIGHTNING_HPP
#define LIGHTNING_HPP

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

struct quadrant{
    int x;
    int y;
};

class Lightnings{

    private:
    
    int cityLength, cityWidth;
    vector<quadrant> vec;
       
    public:
    
    Lightnings(int n, int m){ 
        
        cityLength = n;
        cityWidth = m;

    }

    void add(int x, int y){

        quadrant qToAdd;
        qToAdd.x = x;
        qToAdd.y = y;
        vec.push_back(qToAdd);
        
    }

    int same_place(){
    
        int areInSamePlace = 0;        
    
        for(int k=0; k<vec.size()-1; k++){
            for(int i=1; i<vec.size();  i++)
                if((vec.at(k).x == vec.at(i).x && vec.at(k).y == vec.at(i).y) && k != i){
                    areInSamePlace = 1;
                    break;
                }
            if(areInSamePlace == 1)
                break;  //break for the first for stop incrementing if a duplicate is found
        }

        return areInSamePlace;
    }
};


#endif
