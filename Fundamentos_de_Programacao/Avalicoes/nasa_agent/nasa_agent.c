#include<stdio.h>

//checks if stringA is contained inside stringB
int isContained(char stringA[], char stringB[]){
    
    int isContained=0;
    
//+-------------------------------------------------------------------------------+
    int stringA_size = 0;                                                       //|
    while(stringA[stringA_size] != '\0'){                                         //|
        if(stringA[stringA_size] >= 65 && stringA[stringA_size] <= 90){             //|
            stringA[stringA_size] = stringA[stringA_size] + 32;                     //| código para descobrir o tamaho das strings
        }                                                                       //| e convertá-las para lower case
        stringA_size++;                                                         //|
    }                                                                           //|
    int stringB_size = 0;                                                     //| 
    while(stringB[stringB_size] != '\0'){                                     //|
        if(stringB[stringB_size] >= 65 && stringB[stringB_size] <= 90){     //|
            stringB[stringB_size] = stringB[stringB_size] + 32;             //|                                                   
            }                                                                   //|
        stringB_size++;                                                       //|
    }                                                                           //|
//+-------------------------------------------------------------------------------+

    int charCount=0, track_i=0;
    for(int i = 0; i < stringA_size; i++){
        if(stringA[i] == stringB[0]) {
            charCount++;
            track_i=i;
            for(int j = 1; j < stringB_size; j++){
              
              for(int k=track_i; k<stringA_size; k++){
                  if(stringA[k] == stringB[j]){ 
                    
                    charCount++;
                    track_i=k;
                    break;
                      
                  }
               } 
                
            }
            
            if(charCount == stringB_size) {
                isContained=1;
                break;
            }else{
            charCount = 0;
          }
        }
    }

    
    return isContained;
}

int main(){
    
    printf("Enter First String:\n");
    char stringA[201];
    scanf("%[^\n]", stringA);
    
    printf("\nEnter Second String:\n");
    char stringB[21];
    scanf("%s", stringB);
    
    if(isContained(stringA, stringB)) printf("\nStringB is contained in StringA");
    else printf("\nThe string isn't contained in String A");
    
    
    return 0;
}


