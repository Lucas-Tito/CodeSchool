#include<stdio.h>
#include<stdlib.h>

int binnarySearch(int item){
    
    int inicio=0, fim=1000000, count=0, meio;
    
    while(inicio <= fim){
        
        count++;
        meio = (inicio + fim)/2;    //calcula o meio do vetor
        
        if(vetor[meio] == item)     //se o item estiver no meio, encerra o while
            break;         
        /*
         *Já que o vetor está ordenado, se o elemento no meio for maior que o item
         *O fim passa a ser o meio -1 (é como se todos depois do meio fossem descartados)
         *Já que de tabela todos são maiores que o item
        */ 
        else
            if(vetor[meio] > item)  
                fim = meio - 1;     
        else                         
            inicio = meio + 1;  //se o elemento no meio for menor, o processo é o mesmo, só que dessa vez todos os menores são descartados
    }
 
    return count;   
}


int main(){
   
        /* INPUT */
    printf("Enter a number between 0 and 1000000: ");
    int userNumber;
    scanf("%d", &userNumber);
    
    binnarySearch(userNumber);
    printf("The computer needed %d attempts to guess your number", attempts);
    
    return 0;
}