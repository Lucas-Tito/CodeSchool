#include<stdio.h>

void char_checker(int ToCheck, int *checkLetter, int *checkVowel){
    
//============================FLAGS============================================== 
    int isLetter = ToCheck > 64 && ToCheck < 91 || ToCheck > 96 && ToCheck < 123;
    int isVowel = ToCheck == 65 || ToCheck == 69 || ToCheck == 73 || ToCheck == 79 || ToCheck == 85 || ToCheck == 97 || ToCheck == 101 || ToCheck == 105 || ToCheck == 111 || ToCheck == 117;
//==========================================================================================================================================================================================
    
    if(isLetter){
      *checkLetter=1;
      if(isVowel) *checkVowel=1;
    } 
    
}

int main(){
    
    int checkLetter=0, checkVowel=0;
    char ToCheck;
    scanf("%c", &ToCheck);
    
    char_checker(ToCheck, &checkLetter, &checkVowel);
    
    if(checkLetter)printf("1");
    else printf("0");
    
    if(checkLetter && checkVowel)printf(" V");
    else if(checkLetter && checkVowel==0)printf(" C");
    
    
    return 0;
}