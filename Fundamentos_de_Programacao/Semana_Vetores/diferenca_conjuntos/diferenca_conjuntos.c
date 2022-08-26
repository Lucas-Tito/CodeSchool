#include<stdio.h>

int main(){
        /* ENTRADA */
    int n1;
        scanf("%d", &n1);
    int vetor1[n1];
        for(int i=0; i<n1; i++) scanf("%d", &vetor1[i]);
        
    int n2;
        scanf("%d", &n2);
    int vetor2[n2];
        for(int i=0; i<n2; i++) scanf("%d", &vetor2[i]);
        
         
        /* DECLARAÇÃO DOS VETORES DE INTERSEÇÃO */
    int max_dif= n1;
    int dif[max_dif];
    int n_dif =0; //será o tamanho final do vetor da diferença
    
        
        /* PROCESSAMENTO */
        
    for(int i=0; i<n1; i++){
        int havia=0;
        for(int k=0; k<n2; k++){
            if(vetor1[i]==vetor2[k]){
                havia=1;
                break;
            }
        }
        if(!havia){
            dif[n_dif] = vetor1[i];
            n_dif++;
        }
    }
    
    /* RESULTADOS */
    
    for(int i=0; i<n_dif; i++) printf("%d ", dif[i]);
    
    
    
    
    return 0;
}