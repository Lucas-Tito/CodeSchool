#include<stdio.h>

int main(){
    
    int day, month, year;
    scanf("%d/%d/%d", &day, &month, &year);

//+-----------------------------------------------------------------------------------------------------+
    int isLeapYear = (year%400==0) || (year%4==0 && year%100!=0);                                     //|
    int endsOn28_29 = month==2;                                                                       //|FLAGS  
    int endsOn30 = month==4 || month==6 || month==9 || month==11;                                     //|
    int endsOn31 = month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12;//|
//+-----------------------------------------------------------------------------------------------------+


    if(day>31 || month>12) printf("INVALID");
    
    else if(endsOn28_29){
        
        if(isLeapYear && day<=29) printf("VALID");

        else if(day<=28) printf("VALID");

        else printf("INVALID");
        
    }
    
    else if(endsOn30){
        
        if(day<=30) printf("VALID");

        else printf("INVALID");
        
    }
    
    else if(endsOn31){
        
        if(day<=31) printf("VALID");
        else printf("INVALID");
        
    }
    
    return 0;
}