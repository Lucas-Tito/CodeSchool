#include<stdio.h>

int main(){
    
        /* INPUT */
    char frase[201];
    scanf("%[^\n]", frase);
    
    char aux[201];
        
        /* PROCESS */
        
    //Calcula o tamanho da frase    
    int tamanho_frase=0;
    while(frase[tamanho_frase] != '\0') tamanho_frase++;   //determina os espaços do vetor que estão sendo usados
    
    int i=0;
    while(i<tamanho_frase){
       
        //Calcula o tamanho da palavra
        int tamanho_palavra=0;
        while(frase[i+tamanho_palavra] !=' ' && frase[i + tamanho_palavra] != '\0') tamanho_palavra++;
        
        int j = i;
        while(tamanho_palavra > 0){
            aux[i] = frase[j + tamanho_palavra - 1];
            tamanho_palavra--;
            i++;
        }
        aux[i] = ' ';
        i++;
    }
    aux[tamanho_frase] = '\0';
    
    for(int i = 0; i < tamanho_frase; i++)
        frase[i] = aux[i];
    
    

   
        /* OUTPUT */
    printf("%s", frase);
    return 0;
}