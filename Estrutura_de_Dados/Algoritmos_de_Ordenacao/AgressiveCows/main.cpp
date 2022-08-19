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
    
    int inicio=1, meio, fim= vec[n-1]-vec[0]; //o fim e o início dizem respeito à mínima distância possível e não ao vetor de baias
    
    while(inicio <= fim){
        
        meio = (inicio + fim)/2;    //calcula o meio do vetor
        
        if(canPlaceCow(vec, n, cows, meio))
            inicio = meio+1;
        else
            fim = meio-1;

    }
    
    return meio;
}



int main(){
    
    int nBaias, nVacas;
    cin >> nBaias;
    cin >> nVacas;
    
    int baiaPos[nBaias];
    for(int i=0; i<nBaias; i++)
        cin >> baiaPos[i];
        
    sort(baiaPos, baiaPos+nBaias);    
    cout <<placeCows(baiaPos, nBaias, nVacas) <<endl;
    
    
    return 0;
}
