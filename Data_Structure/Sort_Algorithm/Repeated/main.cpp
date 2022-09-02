#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
                                   
                   
int main(){
    
    int n;
    cin >> n;
    int vet[n];
    
    //receive array data
    for(int i=0; i<n; i++)
        cin >> vet[i];
    
    //puts array data into a vector to facilitate sorting
    vector<int> vetToSort(vet, vet+n);    
    sort(vetToSort.begin(), vetToSort.end());
    
        
    //count duplicates
    int repeated=0, j=0;
    
    for(int i=0; i<n; i++){
        
        if(vetToSort[i] == vetToSort[i+1]){ //after sorting vector, it's verified if the next element is equal to currente element
            repeated++;
            
            for(int j=0; j<n; j++)
                if(vet[i] == vet[j])
                    vet[j] = -1;    //for the same element not be counted 
        }
    }
    
    //prints the amount of repeated elements    
    cout << repeated <<endl;
    
    return 0;
}
