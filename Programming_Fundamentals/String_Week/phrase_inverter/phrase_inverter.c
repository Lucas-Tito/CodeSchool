#include<stdio.h>

int main(){
    
        /* INPUT */
    printf("Enter a phrase: \n");
    char phrase[201];
    scanf("%[^\n]", phrase);
    
    char aux[201];
        
        /* PROCESS */
        
    //Compute phrase size
    int phrase_size=0;
    while(phrase[phrase_size] != '\0') 
        phrase_size++;   
    
    int i=0;
    while(i<phrase_size){
       
        //Compute the size of an word
        int tamanho_palavra=0;
        while(phrase[i+tamanho_palavra] !=' ' && phrase[i + tamanho_palavra] != '\0') 
            tamanho_palavra++;
        
        //do the inverting
        int j = i;
        while(tamanho_palavra > 0){
            aux[i] = phrase[j + tamanho_palavra - 1];
            tamanho_palavra--;
            i++;
        }
        aux[i] = ' ';
        i++;
    }
    aux[phrase_size] = '\0';
    
    for(int i = 0; i < phrase_size; i++)
        phrase[i] = aux[i];    

   
        /* OUTPUT */
    printf("%s", phrase);
    return 0;
}