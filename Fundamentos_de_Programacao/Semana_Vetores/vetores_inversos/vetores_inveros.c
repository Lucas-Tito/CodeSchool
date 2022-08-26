#include<stdio.h>

int main(){
    
        /* ENTRADA DE DADOS */
    int n1;
        scanf("%d", &n1);
        
    int vetor1[n1];
        for(int i=0; i<n1; i++) scanf("%d", &vetor1[i]);
        
    int n2;
        scanf("%d", &n2);
        
    int vetor2[n2];
        for(int i=0; i<n2; i++) scanf("%d", &vetor2[i]);
        
        
    
        /* PROCESSAMENTO */
    if(n1!=n2) printf("Nao Inverso");
    
    else{
        int inverso =1;
        
        for(int i=0; i<n1; i++)
                
            if(vetor1[i]!=vetor2[n1-(i+1)]){
                inverso =0; 
                break;
            }
            
        if(inverso) printf("Inverso");
        else printf("Nao Inverso");  
            }
        
        
    
    
    
    
    return 0;
}