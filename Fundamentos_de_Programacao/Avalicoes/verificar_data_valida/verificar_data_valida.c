#include<stdio.h>

int main(){
    
    int dia, mes, ano;
    scanf("%d/%d/%d", &dia, &mes, &ano);
    
    /* Flags */
    
    int bissexto = (ano%400==0) || (ano%4==0 && ano%100!=0);
    int ate28_29 = mes==2;
    int ate30 = mes==4 || mes==6 || mes==9 || mes==11;
    int ate31 = mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12;
    
    /* Fim das Flags */
   
   
    if(dia>31 || mes>12)
        printf("invalida");
    
    else if(ate28_29){
        
        if(bissexto && dia<=29)
            printf("valida");

        else if(dia<=28)
            printf("valida");

        else 
            printf("invalida");
        
    }
    
    else if(ate30){
        
        if(dia<=30)
            printf("valida");
        else 
            printf("invalida");
        
    }
    
    else if(ate31){
        
        if(dia<=31)
            printf("valida");
        else 
            printf("invalida");
        
    }
    
    
    return 0;
}