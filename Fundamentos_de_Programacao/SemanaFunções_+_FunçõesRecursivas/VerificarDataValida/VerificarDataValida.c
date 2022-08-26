#include<stdio.h>

typedef struct{
    
  int dia, mes, ano;
  
    
}Data;

int dateValidate(Data toVerify){
    int isValid=0;
    
    /* Flags */
    int bissexto = (toVerify.ano%400==0) || (toVerify.ano%4==0 && toVerify.ano%100!=0);
    int ate28_29 = toVerify.mes==2;
    int ate30 = toVerify.mes==4 || toVerify.mes==6 || toVerify.mes==9 || toVerify.mes==11;
    int ate31 = toVerify.mes==1 || toVerify.mes==3 || toVerify.mes==5 || toVerify.mes==7 || toVerify.mes==8 || toVerify.mes==10 || toVerify.mes==12;
    /* Fim das Flags */
   
   
    if(toVerify.dia>31 || toVerify.mes>12)isValid=0;
    
    else if(ate28_29){
        
        if(bissexto && toVerify.dia<=29) isValid=1;
        else if(toVerify.dia<=28) isValid=1;
        else isValid=0;
        
    }
    
    else if(ate30){
        
        if(toVerify.dia<=30) isValid=1;
        else isValid=0;
        
    }
    
    else if(ate31){
        
        if(toVerify.dia<=31) isValid=1;
        else isValid=0;
        
    }
    
    return isValid;
}

int main(){
    
    Data toVerify;
    scanf("%d/%d/%d", &toVerify.dia, &toVerify.mes, &toVerify.ano);
    
    printf("%d", dateValidate(toVerify));
    
    
    return 0;
}