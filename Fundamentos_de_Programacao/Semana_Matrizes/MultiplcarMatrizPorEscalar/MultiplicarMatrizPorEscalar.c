#include<stdio.h>

int main(){
        
        /* INPUT */
    int n, m;
    scanf("%d %d", &n, &m);
        
    int matrizA[n][m];
    for(int l=0; l<n; l++) for(int c=0; c<m; c++) scanf("%d", &matrizA[l][c]);
    
    int escalar;
    scanf("%d", &escalar);
    
        /* PROCESS & OUTPUT */
    int matrizB[n][m];
    for(int l=0; l<n; l++){
        
        for(int c=0; c<m; c++){
            
            matrizB[l][c] = matrizA[l][c] * escalar;
            printf("%d ", matrizB[l][c]);
            
        }
        printf("\n");
        
    }
    
    
    
    
    return 0;
}