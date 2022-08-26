#include<stdio.h>

int main(){
    
        /* INPUT */
    int LeC;                //linhas e colunas
    scanf("%d", &LeC);
    
    int matriz_quadrada[LeC][LeC];
    for(int l=0; l<LeC; l++) for(int c=0; c<LeC; c++) scanf("%d", &matriz_quadrada[l][c]);
    
        /* PROCESS */
    int soma_diagonal=0;
    for(int l=0; l<LeC; l++){
    
        soma_diagonal += matriz_quadrada[l][l]; 
       
    }
        
        /* OUTPUT */
    printf("%d", soma_diagonal);
    
    return 0;
}