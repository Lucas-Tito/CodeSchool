#includestdio.h

int main(){
    
     DECLARAÇÃO E ATRIBUIÇÃO DOS VETORES 
    
    int qtd1;
        scanf(%d, &qtd1);
        
    int vetor1[qtd1];
        for(int i=0; iqtd1; i++) scanf(%d, &vetor1[i]);
        
    int qtd2;
        scanf(%d, &qtd2);
    
    int vetor2[qtd2];
        for(int i=0; iqtd2; i++) scanf(%d, &vetor2[i]);
        
        
    
    
     PROCESSAMENTO 
    int igual =0;
    
    for(int i=0; iqtd1; i++)
    
        for(int k=0; kqtd2; k++){
            
            if(vetor1[i]==vetor2[k]){ 
            
                igual += 1;
                break;
                
            }
            
        }
    
            
    if(igual == qtd1) printf(Contido);
    else printf(Nao contido);
    
    
    return 0;
}