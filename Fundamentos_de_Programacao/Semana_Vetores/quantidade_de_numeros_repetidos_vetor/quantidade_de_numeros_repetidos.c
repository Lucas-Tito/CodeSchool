#include<stdio.h>

int main(){
    
        /* INPUT */
    int n;
    scanf("%d", &n);
        
    int vetor[n];
    for(int i=0; i<n; i++) scanf("%d", &vetor[i]);
    
    
        /* PROCESS */
    int repeticao=0;
    for(int i=0; i<n; i++){
        for(int k=i+1; k<n; k++)
            if(vetor[i]==vetor[k]){
                repeticao +=1;
            } 
    }
            
            /* OUTPUT */
        printf("%d", repeticao);
    
    return 0;
}