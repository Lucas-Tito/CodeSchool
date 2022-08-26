#include <stdio.h>

int main(){
        /* INPUT */
    char cadeia1[101], cadeia2[101];
    scanf("%[^\n] ", cadeia1);
    scanf(" %[^\n]", cadeia2);
    
        /* PROCESS */
    int contA = 0;
    while(cadeia1[contA] != '\0') contA++;
    int contB = 0;
    while(cadeia2[contB] != '\0') contB++;

    int init = -1, contChar = 0, havia=0;
    
    for(int i = 0; i < contA; i++){
        if(cadeia1[i] == cadeia2[0]) {
          int guardaI = i + 1;
          init = i;
          contChar++;
          for(int j = 1; j < contB ; j++, guardaI++){
            if(cadeia1[guardaI] == cadeia2[j]) {
              contChar++;
            }
          }
          if(contChar == contB) {
            havia=1;
            break;
          }else{
            contChar = 0;
          }
        }
    }    
    
        /* OUTPUT */
    if(havia) printf("%d", init);
    else printf("%d", -1);
    return 0;
}