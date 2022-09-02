#include<iostream>
#include<stdbool.h>
#include <algorithm>  
using namespace std;

bool canPlaceCow(int *vec, int nVec, int cows, int distance){
    
    bool canPlace = false;
    int cowsPlaced =1, lastCowCordinate = vec[0];
    
    for(int i=1; i<nVec; i++){
        if(vec[i]-lastCowCordinate>=distance){
            cowsPlaced++;
            lastCowCordinate=vec[i];
        }
        
        if(cowsPlaced==cows){
            canPlace = true;
            break;
        }
    }
        
        
    return canPlace;
}


int placeCows(int *vec, int n, int cows){
    
    int low=1, middle, high= vec[n-1]-vec[0]; //high and low are about the minimum distance possible
    
    while(low <= high){
        
        middle = (low + high)/2;    //compute the middle of the vector
        
        if(canPlaceCow(vec, n, cows, middle))
            low = middle+1;
        else
            high = middle-1;

    }
    
    return middle;
}



int main(){
    
    int nBays, nCows;
    cin >> nBays;
    cin >> nCows;
    
    int bayPos[nBays];
    for(int i=0; i<nBays; i++)
        cin >> bayPos[i];
        
    sort(bayPos, bayPos+nBays);    
    cout <<placeCows(bayPos, nBays, nCows) <<endl;
    
    
    return 0;
}
