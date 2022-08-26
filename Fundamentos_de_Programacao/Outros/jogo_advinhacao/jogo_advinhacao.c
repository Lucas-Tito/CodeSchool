#include<stdio.h>
#include<stdlib.h>

int main(){
   
        /* INPUT */
    printf("Informe o numero: ");
    int DrawnByUser;
    scanf("%d", &DrawnByUser);
    
        /* PROCESS */
    srand(time(NULL));
    int chute =0, tentativas=0;
   
    do{
        //printf("A maquina tentara adivinhar a chave: ");
        if(tentativas==0)  chute = rand() % 1024 + 1;         // se for a primeira tentavia, a máquina chuta aleatoriamente
        
        if(chute>DrawnByUser){
            //printf("O chute da máquina foi maior\n");
            chute--;
        }
            
        else if(chute<DrawnByUser){
            //printf("O chute da máquina foi menor\n");
            chute++;
        }
        tentativas++;
        
    }while(chute!=DrawnByUser);
    
    printf("A máquina precisou de %d tentativas para acertar", tentativas);
   
    
    
    
    return 0;
}