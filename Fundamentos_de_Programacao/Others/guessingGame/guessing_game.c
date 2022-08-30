#include<stdio.h>
#include<stdlib.h>

int binnarySearch(int item){
    
    int low=0, high=1000000, attempts=0, mid;
    
    while(low <= high){
        
        attempts++;
        mid = (low + high)/2;    //calcula o mid do vetor
        
        if(mid == item)     //se o item estiver no mid, encerra o while
            break;         
        /*
         *Já que o vetor está ordenado, se o elemento no mid for maior que o item
         *O high passa a ser o mid -1 (é como se todos depois do mid fossem descartados)
         *Já que de tabela todos são maiores que o item
        */ 
        else
            if(mid > item)  
                high = mid - 1;     
        else                         
            low = mid + 1;  //se o elemento no mid for menor, o processo é o mesmo, só que dessa vez todos os menores são descartados
    }
    printf("\nend number = %d\n", mid);
    return attempts;   
}


int main(){
   
        /* INPUT */
    printf("Enter a number between 0 and 1000000: ");
    int userNumber;
    scanf("%d", &userNumber);
    
    int attempts = binnarySearch(userNumber);
    printf("The computer needed %d attempts to guess your number", attempts);

    printf("\nuser number = %d\n", userNumber);
    return 0;
}