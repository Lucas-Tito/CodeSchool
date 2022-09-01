#include<iostream>
#include<queue>
#include<stdbool.h>

using namespace std;


typedef struct{
    
    int gasAvailable;
    int nextGasStation;
    int position;

} Bomba;



int main(){
    
    int n;
    cin >> n;
    
    vector<Bomba> b;
    Bomba bToAdd;
    int gasOnTheTruck = 0;
    int startingPoint = 0;
    
    for(int i=0; i<n; i++){
        cin >> bToAdd.gasAvailable >> bToAdd.nextGasStation; 
        bToAdd.position=i;
        b.push_back(bToAdd);
    }
            
    for(int i=0; i<n; i++){   //for para verificar se toda a viajem pode ser feita
            
        gasOnTheTruck += b[i].gasAvailable - b[i].nextGasStation;
            
        if(gasOnTheTruck + b[i].gasAvailable < b[i].nextGasStation){
            gasOnTheTruck = 0;
            startingPoint = i + 1;
        }
        else
            gasOnTheTruck += b[i].gasAvailable - b[i].nextGasStation;
        
    }
        
    
    cout << startingPoint << endl;
    
    
    return 0;
}
