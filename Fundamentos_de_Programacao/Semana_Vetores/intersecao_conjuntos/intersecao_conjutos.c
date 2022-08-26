#include<stdio.h>

int main(){
        /* DECLARAÇÃO DOS VETORES DE ENTRADA */
    int n1;
        scanf("%d", &n1);
        
    int vetor1[n1];
        for(int i=0; i<n1; i++) scanf("%d", &vetor1[i]);
        
    int n2;
        scanf("%d", &n2);
        
    int vetor2[n2];
        for(int i=0; i<n2; i++) scanf("%d", &vetor2[i]);
        
        /* DECLARAÇÃO DOS VETORES DE INTERSEÇÃO */
    int max_inter= (n1>=n2 ? n1 : n2);
    int inter[max_inter];
    int n_inter =0; //será o tamanho final do vetor de interseção
    
        /* PROCESSAMENTO */
        
    for(int i=0; i<n1; i++){
        int havia =0;
        for (int k=0; k<n2; k++){
            if(vetor1[i]==vetor2[k]){
                
                havia =1;
                break;
                
            } 

        }
        if(havia){
            inter[n_inter] = vetor1[i];
            n_inter++;              
        }
    }
    /* RESULTADOS */
    
    for(int i=0; i<n_inter; i++) printf("%d ", inter[i]);
    
    
    return 0;
}