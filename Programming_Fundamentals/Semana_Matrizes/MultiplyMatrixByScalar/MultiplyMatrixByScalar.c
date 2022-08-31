#include<stdio.h>

int main(){
        
        /* INPUT */
    printf("Enter the matrix dimensions: ");
    int n, m;
    scanf("%d %d", &n, &m);
    
    printf("Enter the matrix elements: ");
    int matrixA[n][m];
    for(int l=0; l<n; l++) 
        for(int c=0; c<m; c++) 
            scanf("%d", &matrixA[l][c]);
    
    printf("Enter the scalar: ");
    int scalar;
    scanf("%d", &scalar);
    
        /* PROCESS & OUTPUT */
    int matrixB[n][m];  //auxiliary variable
    printf("\nResult:\n");
    for(int l=0; l<n; l++){
        
        for(int c=0; c<m; c++){
            
            matrixB[l][c] = matrixA[l][c] * scalar;
            printf("%d ", matrixB[l][c]);
            
        }
        printf("\n");
        
    }
    
    
    
    
    return 0;
}