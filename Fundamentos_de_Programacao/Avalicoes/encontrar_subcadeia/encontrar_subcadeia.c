#include <stdio.h>

int main(){

      /* INPUT */
  char cadeia1[101], cadeia2[101];
  scanf("%[^\n] ", cadeia1);    //store everything entered until enter get pressed
  scanf(" %[^\n]", cadeia2);
    
      /* PROCESS */
  int contA = 0;
  while(cadeia1[contA] != '\0') contA++;  //count how many characteres in cadeiaA

  int contB = 0;
  while(cadeia2[contB] != '\0') contB++;  //count how many characteres in cadeiaB

  int init = -1, contChar = 0, havia=0;
    
  for(int i = 0; i < contA; i++){

    if(cadeia1[i] == cadeia2[0]) {    //search for a character equal to the first charactere of stringB
      int guardaI = i + 1;
      init = i;
      contChar++;
      for(int j = 1; j < contB ; j++, guardaI++){   //determine if stringB is after the encountered character
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