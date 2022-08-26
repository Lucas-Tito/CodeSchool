#include<stdio.h>

int main(){
        /* INPUT */
    int n;
    scanf("%d", &n);
    int vetor_input[n];
    for(int i=0; i<n; i++) scanf("%d", &vetor_input[i]);
    
        /* PROCESS */
    
    for(int i=0, k=n-1; i<n/2; i++, k--){
     
            int anterior = vetor_input[i];
             vetor_input[i]=vetor_input[k];
             vetor_input[k] = anterior;
        }  
        
        /* OUTPUT */
    for(int i=0; i<n; i++) printf("%d ", vetor_input[i]);
    return 0;
}