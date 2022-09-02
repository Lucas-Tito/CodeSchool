#include <iostream>
#include <algorithm>
using namespace std;


int bubblesort(int *vetor, int n){
    int count =0;
    bool swapped = true;
    
    while(swapped){
        swapped = false;
        count++;
        
        for(int i=0; i<n-1; i++)
            if(vetor[i] > vetor[i+1]){
                swap(vetor[i], vetor[i+1]);
                swapped = true;
            }
    }
    
    
    return count;
}


int main(){
    
    int n;
    
    //cout << "Enter N:" << endl;
    cin >> n;
    int vet[n];
    
    //cout << "Enter vector elements:" << endl;
    for(int i = 0; i<n; i++)
        cin >> vet[i]; 
    
    
    cout << bubblesort(vet, n) << endl;
    
    return 0;    
}
