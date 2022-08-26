#include<stdio.h>

int main(){
        /* INPUT */
    int n;
    scanf("%d", &n);
    
    int vetor[n];
    for(int i=0; i<n; i++) scanf("%d", &vetor[i]);
    
    int chave;
    scanf("%d", &chave);
        
        /* DECLARAÇÃO DO VETOR DE RESULTADO */
    int vetor_result[n];
    int n_result =0; //será o tamanho final do vetor do resultado
        
        /* PROCESS */
    
    for(int i=0; i<n; i++){
        //impar
        if(chave==1 && vetor[i]%2!=0) vetor_result[n_result++] = vetor[i];
        
        //par
        if(chave==2 && vetor[i]%2==0) vetor_result[n_result++] = vetor[i];
    
        //positivo
        if(chave==3 && vetor[i]>=0) vetor_result[n_result++] = vetor[i];
        
        //negativo
        if(chave==4 && vetor[i]<0) vetor_result[n_result++] = vetor[i];
    }   
   
    
        /* OUTPUT */
   for(int i=0; i<n_result; i++) printf("%d ", vetor_result[i]);
    
    
    
    return 0;