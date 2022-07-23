#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

struct Operation{   //Criei um tipo para ser mais simples entender o código
    int type;
    int value;
};

//COMO É NECESSÁRIO ORDERNAR A CADA NOVA INSERÇÃO, O INSERTION SORT É O MAIS OTIMIZADO PARA ESTA APLICAÇÃO

void insertionSort(int* vetor, int n){
    /*
     *j sempre irá guardar a posição anterior do atual elemento percorrido do vetor
     *key guarda o elemento atual que está sendo percorrido no vetor
    */
    int key, j;    
    for (int i = 1; i < n; i++){
        key = vetor[i];
        j = i - 1;
        
        while (j >= 0 && vetor[j] > key){
            
            vetor[j + 1] = vetor[j];    // move o elemento maior que key para uma posição a frente
            j--;
            
        }
        vetor[j + 1] = key;
    }
}


int main(){

    int n, count=0;
    cin >> n;
    int vetor[n];  
    Operation op;

    for(int i=0; i<n; i++){     //recebe as operações e valores
        cin >> op.type;
        cin >> op.value;

        if(op.type == 2){
            cout << vetor[op.value] << endl;
        }       
        else{
            vetor[count]=op.value;    //adiciona valor no vetor quando a operação for igual a 1
            count++;
            insertionSort(vetor, count); //passa count para ordenar apenas o que já foi populado do vetor   
        }

    }
    
    return 0;
}
