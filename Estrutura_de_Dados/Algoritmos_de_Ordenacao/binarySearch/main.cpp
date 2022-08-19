#include<iostream>
using namespace std;

int busca_binariaCount(int *vetor, int n, int item){
    
    int inicio=0, fim=n-1, count=0, meio;
    
    while(inicio <= fim){
        
        count++;
        meio = (inicio + fim)/2;    //calcula o meio do vetor
        
        if(vetor[meio] == item)     //se o item estiver no meio, encerra o while
            break;         
        /*
         *Já que o vetor está ordenado, se o elemento no meio for maior que o item
         *O fim passa a ser o meio -1 (é como se todos depois do meio fossem descartados)
         *Já que de tabela todos são maiores que o item
        */ 
        else
            if(vetor[meio] > item)  
                fim = meio - 1;     
        else                         
            inicio = meio + 1;  //se o elemento no meio for menor, o processo é o mesmo, só que dessa vez todos os menores são descartados
    }
 
    return count;   
}

void populateVec(int* vec, int n){
    
    for(int i=0; i<n; i++)
        cin >> vec[i];
    
}

int main(){
    
    int nVec, nQuestions;
    cin >> nVec;
    cin >> nQuestions;
    
    int sortedVec[nVec], questionsVec[nQuestions];
    populateVec(sortedVec, nVec);
    populateVec(questionsVec, nQuestions);
      
    for(int i=0; i<nQuestions; i++){
        if(i == nQuestions-1)
            cout << busca_binariaCount(sortedVec, nVec, questionsVec[i]) << endl;
        else
            cout << busca_binariaCount(sortedVec, nVec, questionsVec[i]) << " ";
    }
    
    
    return 0;
}
