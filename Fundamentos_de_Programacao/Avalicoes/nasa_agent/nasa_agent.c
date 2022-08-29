#include<stdio.h>

int isContained(char email[], char palavra[]){
    
    int isContained=0;
    
//+-------------------------------------------------------------------------------+
    int tamanhoEmail = 0;                                                       //|
    while(email[tamanhoEmail] != '\0'){                                         //|
        if(email[tamanhoEmail] >= 65 && email[tamanhoEmail] <= 90){             //|
            email[tamanhoEmail] = email[tamanhoEmail] + 32;                     //| código para descobrir o tamaho das strings
        }                                                                       //| e convertá-las para lower case
        tamanhoEmail++;                                                         //|
    }                                                                           //|
    int tamanhoPalavra = 0;                                                     //| 
    while(palavra[tamanhoPalavra] != '\0'){                                     //|
        if(palavra[tamanhoPalavra] >= 65 && palavra[tamanhoPalavra] <= 90){     //|
            palavra[tamanhoPalavra] = palavra[tamanhoPalavra] + 32;             //|                                                   
            }                                                                   //|
        tamanhoPalavra++;                                                       //|
    }                                                                           //|
//+-------------------------------------------------------------------------------+

    int contChar=0, guardaI=0;
    for(int i = 0; i < tamanhoEmail; i++){
        if(email[i] == palavra[0]) {
            contChar++;
            guardaI=i;
            for(int j = 1; j < tamanhoPalavra; j++){
              
              for(int k=guardaI; k<tamanhoEmail; k++){
                  if(email[k] == palavra[j]){ 
                    
                    contChar++;
                    guardaI=k;
                    break;
                      
                  }
               } 
                
            }
            
            if(contChar == tamanhoPalavra) {
                isContained=1;
                break;
            }else{
            contChar = 0;
          }
        }
    }

    
    return isContained;
}

int main(){
    
    char email[201];
    scanf("%[^\n]", email);
    
    char palavra[21];
    scanf("%s", palavra);
    
    if(isContained(email, palavra)) printf("Sim");
    else printf("Nao");
    
    
    return 0;
}


