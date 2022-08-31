#include<stdio.h>
#include<stdlib.h>

int* expandir_vetor(int* vetor1, int n, int* vetor2, int m){
    
    int* vetor_expandido = (int*)malloc((n+m)*sizeof(int));
    
    for(int i=0; i<n; i++) vetor_expandido[i]=vetor1[i];
    for(int i=0; i<m; i++) vetor_expandido[i+n]=vetor2[i];
    
    free(vetor1);
    free(vetor2);
    
    return vetor_expandido;
}

int main(){
    
    /* INPUT */
    int n;
    scanf("%d", &n);
    
    int *vetor1 = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++) scanf("%d", &vetor1[i]);
    
    int m;
    scanf("%d", &m);
    
    int *vetor2 = (int*)malloc(m*sizeof(int));
    for(int i=0; i<m; i++) scanf("%d", &vetor2[i]);
    
    
    /* PROCESS */
    int* vetor_expandido = expandir_vetor(vetor1, n, vetor2, m);
    
    
    /* OUTPUT */
    for(int i=0; i<n+m; i++) printf("%d ", vetor_expandido[i]);
    
    free(vetor_expandido);
    
    return 0;
}