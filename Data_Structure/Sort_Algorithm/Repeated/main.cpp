#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
                                   
                   
int main(){
    
    int n;
    
    //recebe n
    cin >> n;
    int vet[n];
    
    //recebe os dados do vetor 
    for(int i=0; i<n; i++)
        cin >> vet[i];
    
    //coloca os dados do vetor num vector para facilitar a utilização da função sort
    vector<int> vetToSort(vet, vet+n);    
    sort(vetToSort.begin(), vetToSort.end());
    
        
    //conta os repetidos
    int repetidos=0, j=0;
    
    for(int i=0; i<n; i++){
        
        if(vetToSort[i] == vetToSort[i+1]){ //depois de ordenar os vetores, é verificado se o próximo é igual ao anterior
            repetidos++;
            
            for(int j=0; j<n; j++)
                if(vet[i] == vet[j])
                    vet[j] = -1;    // para o mesmo elemento não ser contado como repetição duas ou + vezes 
        }
    }
    
    //imprime o número de repetidos    
    cout << repetidos <<endl;
    
    return 0;
}
