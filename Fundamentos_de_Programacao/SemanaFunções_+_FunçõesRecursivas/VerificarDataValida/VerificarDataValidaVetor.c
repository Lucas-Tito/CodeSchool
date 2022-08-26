#include<stdio.h>
#include<stdlib.h>

typedef struct{
    
  int dia, mes, ano;
  
    
}Data;

int datesValidate(Data toVerify[], int n){
    int HowManyisValid=0;
   
   for(int i=0; i<n; i++){
       
       /* Flags */
    int bissexto = (toVerify[i].ano%400==0) || (toVerify[i].ano%4==0 && toVerify[i].ano%100!=0);
    int ate28_29 = toVerify[i].mes==2;
    int ate30 = toVerify[i].mes==4 || toVerify[i].mes==6 || toVerify[i].mes==9 || toVerify[i].mes==11;
    int ate31 = toVerify[i].mes==1 || toVerify[i].mes==3 || toVerify[i].mes==5 || toVerify[i].mes==7 || toVerify[i].mes==8 || toVerify[i].mes==10 || toVerify[i].mes==12;
    /* Fim das Flags */
       
       
       if(toVerify[i].dia>31 || toVerify[i].mes>12) HowManyisValid+=0;
    
    else if(ate28_29){
        
        if(bissexto && toVerify[i].dia<=29) HowManyisValid++;
        else if(toVerify[i].dia<=28) HowManyisValid++;
        else HowManyisValid+=0;
        
    }
    
    else if(ate30){
        
        if(toVerify[i].dia<=30) HowManyisValid++;
        else HowManyisValid+=0;
        
    }
    
    else if(ate31){
        
        if(toVerify[i].dia<=31) HowManyisValid++;
        else HowManyisValid+=0;
        
    }
       
   }
    
    
    return HowManyisValid;
}

int main(){
    
    int n;
    scanf("%d", &n);
    
    Data* toVerify=(Data*)malloc(n*sizeof(Data));
    for(int i=0; i<n; i++) scanf("%d/%d/%d", &toVerify[i].dia, &toVerify[i].mes, &toVerify[i].ano);
    
    printf("%d", datesValidate(toVerify, n));
    
    free(toVerify);
    
    
    return 0;
}