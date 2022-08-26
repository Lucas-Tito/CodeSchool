#include<stdio.h>

typedef struct{
      char nome[100];
      float notas[3];
      float media;
}Aluno;

void sumCalc(Aluno vetor[], float n, float media_geral){
    
    for(int i=0; i<n; i++){
        vetor[i].media = (vetor[i].notas[0] + vetor[i].notas[1] + vetor[i].notas[2])/3;
        
        if(vetor[i].media >= media_geral) printf("%s\n", vetor[i].nome);
    }
    
}

int main(){
    
    /* INPUT */
    int n;
    scanf("%d", &n);
    
    Aluno alunos[n];
    for(int i=0; i<n; i++){
        scanf(" %[^\n]", alunos[i].nome);
        scanf("%f %f %f", &alunos[i].notas[0], &alunos[i].notas[1], &alunos[i].notas[2]);
    }
    
    float media_geral;
    scanf("%f", &media_geral);
    
    /* PROCESS */
    
    sumCalc(alunos, n, media_geral);
    
    return 0;
}