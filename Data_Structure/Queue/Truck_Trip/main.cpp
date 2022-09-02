#include<iostream>
#include<queue>
#include<stdbool.h>

using namespace std;


typedef struct{
    
    int gasAvailable;
    int nextGasStation;
    int position;

} GasStation;



int main(){
    
    int n;
    cin >> n;
    
    vector<GasStation> b;
    GasStation bToAdd;
    int gasOnTheTruck = 0;
    int startingPoint = 0;
    
    for(int i=0; i<n; i++){
        cin >> bToAdd.gasAvailable >> bToAdd.nextGasStation; 
        bToAdd.position=i;
        b.push_back(bToAdd);
    }
            
    for(int i=0; i<n; i++){   //for to verify if the whole trip can be done
            
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
