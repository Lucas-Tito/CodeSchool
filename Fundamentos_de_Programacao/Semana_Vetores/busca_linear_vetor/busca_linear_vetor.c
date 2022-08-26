#include<stdio.h>

int main(){
    
    int n;
        scanf("%d", &n);
    
    int vetor[n];
        for(int i=0; i<n; i++) scanf("%d", &vetor[i]);
        
    int chave, chave_encontrada;
        scanf("%d", &chave);
        
    for(int i=0; i<n; i++){
        
        if(chave == vetor[i]){ 
            
            printf("%d", i);
            chave_encontrada = 1;
            break;
        }
    }
    
    if(!chave_encontrada)printf("-1");
    
    
    return 0;
}