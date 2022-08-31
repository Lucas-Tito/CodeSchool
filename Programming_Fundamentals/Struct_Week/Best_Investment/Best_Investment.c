#include<stdio.h>
#include<limits.h>

typedef struct{
    float profitabilityPercent, exitFee;
}fixedApplication;

float bestApplication(fixedApplication vetor[], int n, int initialValue){
    
    float bestApplication = INT_MIN;
    for(int i=0; i<n; i++){
        
        float applicationValue = (initialValue * (vetor[i].profitabilityPercent/100)) -
        ((initialValue * (vetor[i].profitabilityPercent/100))*(vetor[i].exitFee/100));
        
        if(applicationValue>bestApplication) 
            bestApplication = applicationValue;
    }
    
    return bestApplication;    
}


int main(){
    
    /* INPUT */
    printf("Enter how many applications will be compared: \n");
    int n;
    scanf("%d", &n);
    
    printf("Enter applications profits percents and exit fees: \n");
    fixedApplication values[n];
    for(int i=0; i<n; i++) 
        scanf("%f %f", &values[i].profitabilityPercent, &values[i].exitFee);
    
    int initialValue;
    scanf("%d", &initialValue);
    
    /* PROCESS */
    
    
    printf("\nThis is the best application: %.2f", bestApplication(values, n, initialValue));
    
    
    return 0;
}