#include<stdio.h>

typedef struct{
    int linha, coluna;
}Coordinate;


int main(){
    
    int n;
    scanf("%d", &n);
    
    int matriz[n][n];
    for(int l=0; l<n; l++) 
        for(int c=0; c<n; c++) 
            scanf("%d", &matriz[l][c]);
    
    Coordinate playerChoice;
    scanf("%d %d", &playerChoice.linha, &playerChoice.coluna);
    
    int result=0;
    if(matriz[playerChoice.linha][playerChoice.coluna]<0) printf("Perdeu!");
    
    else {
        
        if(playerChoice.linha-1>0) result += matriz[playerChoice.linha-1][playerChoice.coluna];
        if(playerChoice.linha+1<n) result += matriz[playerChoice.linha+1][playerChoice.coluna];
        if(playerChoice.coluna-1>0) result += matriz[playerChoice.linha][playerChoice.coluna-1];
        if(playerChoice.coluna+1<n) result += matriz[playerChoice.linha][playerChoice.coluna+1];
        
        result += matriz[playerChoice.linha][playerChoice.coluna];
        printf("%d", result);
        
    }
    
    
    
    return 0;
}