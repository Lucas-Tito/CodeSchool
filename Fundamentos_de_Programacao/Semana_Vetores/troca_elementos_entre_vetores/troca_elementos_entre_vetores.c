#include<stdio.h>

int main(){
    
    int n, var1, var2;
        scanf("%d", &n);
    
    int vetor1[n], vetor2[n];
    
    for(int i=0; i<n; i++) scanf("%d", &vetor1[i]);
    
    for(int i=0; i<n; i++) scanf("%d", &vetor2[i]);
    
    for(int i=0; i<n; i++){
        
        if(i%2==0){
        var1= vetor2[i];
        printf("%d ", var1);
        }
        else printf("%d ", vetor1[i]);
    }
    
    for(int i=0; i<n; i++){
        
        if(i%2==0){
        var2= vetor1[i];
        printf("%d ", var2);
        }
        else printf("%d ", vetor2[i]);
    }
    
    
    
    return 0;
}