#include<stdio.h>

typedef struct{
    int line, colum;
}Coordinate;


int main(){
    
    printf("Enter how many matrix elements: \n")
    int n;
    scanf("%d", &n);
    
    printf("Enter matrix elements: \n");
    int matrix[n][n];
    for(int l=0; l<n; l++) 
        for(int c=0; c<n; c++) 
            scanf("%d", &matrix[l][c]);
    
    printf("Enter your cordinate choice: \n");
    Coordinate playerChoice;
    scanf("%d %d", &playerChoice.line, &playerChoice.colum);
    
    int result=0;
    if(matrix[playerChoice.line][playerChoice.colum]<0) printf("You Lost!");
    
    else {
        
        if(playerChoice.line-1>0) result += matrix[playerChoice.line-1][playerChoice.colum];
        if(playerChoice.line+1<n) result += matrix[playerChoice.line+1][playerChoice.colum];
        if(playerChoice.colum-1>0) result += matrix[playerChoice.line][playerChoice.colum-1];
        if(playerChoice.colum+1<n) result += matrix[playerChoice.line][playerChoice.colum+1];
        
        result += matrix[playerChoice.line][playerChoice.colum];
        printf("%d", result);
        
    }
    
    
    
    return 0;
}