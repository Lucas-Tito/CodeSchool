#include<stdio.h>
#include<stdlib.h>

typedef struct{
    
    int id, stock;
    float price;
  
}Produto;

void ValueNStock(Produto produtos[], int n, int vendas[], float* total_price, int stock[]){
    
    for(int i=0; i<n; i++){
        *total_price+= produtos[i].price*vendas[i];
        stock[i]= produtos[i].stock - vendas[i];
    }
    
}

int main(){
    
    /* INPUT */
    int n;
    scanf("%d", &n);
    
    Produto* produtos = (Produto*)malloc(n*sizeof(Produto));
    for(int i=0; i<n; i++) scanf("%d %d %f", &produtos[i].id, &produtos[i].stock, &produtos[i].price);
    
    int vendas[n];
    for(int i=0; i<n; i++) scanf("%d ", &vendas[i]);
    
    /* PROCESS */
    
    float total_price=0;
    int stock[n];
    
    ValueNStock(produtos, n, vendas, &total_price, stock);
    printf("%.2f\n", total_price);
    for(int i=0; i<n; i++) printf("%d ", stock[i]);
    
    
    
    return 0;
}