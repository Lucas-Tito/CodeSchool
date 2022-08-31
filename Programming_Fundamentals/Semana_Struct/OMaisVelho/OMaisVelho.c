#include<stdio.h>
#include<limits.h>

typedef struct{
    
  int dia, mes, ano;
  
    
}BirthDate;

int isFullYear(BirthDate nascimento, int data_atual[]){                //FUNÇÃO QUE INFORMA SE O ANO É COMPLETO
    
    int isFullYear=0;
    if (nascimento.mes - data_atual[1] <=0){
        if(nascimento.dia - data_atual[0] >0){
            if(nascimento.mes - data_atual[1] ==0){ isFullYear=0;}else isFullYear=1;
            
        }
        else if(nascimento.dia - data_atual[0] <=0){ isFullYear=1;
       
    }else if(nascimento.mes - data_atual[1] <0){
        if(nascimento.dia - data_atual[0] >0){
            if(nascimento.mes - data_atual[1] ==0){isFullYear=0;}else isFullYear=1;
        }
       
    }}else isFullYear=0;
    
    return isFullYear;
}



int WhoIsOlder(BirthDate vetor[], int n, int data_atual[]){       //FUNÇÃO QUE INFORMA A IDADE A PESSOA MAIS VELHA
    
    int olderOne= INT_MIN, idade=0;
    for(int i=0; i<n; i++){
        
        if(isFullYear(vetor[i], data_atual)) idade = data_atual[2] - vetor[i].ano;
        else idade = data_atual[2] - vetor[i].ano -1;
        
        if(idade>olderOne) olderOne = idade;
         
    }
    
    return olderOne;
}




int main(){
    
    /* INPUT */
    int n;
    scanf("%d", &n);
    
    BirthDate pessoa[n];
    for(int i=0; i<n; i++) scanf("%d %d %d", &pessoa[i].dia, &pessoa[i].mes, &pessoa[i].ano);
    
    int data_atual[3];
    scanf("%d %d %d", &data_atual[0], &data_atual[1], &data_atual[2]);
    
    /* PROCESS */
    
    printf("%d", WhoIsOlder(pessoa, n, data_atual));
    
    
    return 0;
}