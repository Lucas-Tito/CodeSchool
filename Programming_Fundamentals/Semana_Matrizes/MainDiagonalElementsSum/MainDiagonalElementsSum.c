#include<stdio.h>

int main(){
    
        /* INPUT */
    
    printf("Enter ONE NUMBER to determine the lines and coluns: ");
    int LnC;    //lines and coluns (they need to have the same value)
    scanf("%d", &LnC);
    
    printf("Enter the matrix elements: ");
    int square_matrix[LnC][LnC];
    for(int l=0; l<LnC; l++) 
        for(int c=0; c<LnC; c++)
            scanf("%d", &square_matrix[l][c]);
    
        /* PROCESS */
    int diagonal_sum=0;
    for(int l=0; l<LnC; l++)
        diagonal_sum += square_matrix[l][l]; 
       
    
        
        /* OUTPUT */
    printf("\nResult: %d", diagonal_sum);
    
    return 0;
}