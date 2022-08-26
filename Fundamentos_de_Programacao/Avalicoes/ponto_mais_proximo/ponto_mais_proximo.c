#include<stdio.h>
#include<math.h>
#include<limits.h>

typedef struct{
     float x, y; 
}Ponto;

float distancia(Ponto p1, Ponto p2){
    
    float result = sqrt( pow((p2.x-p1.x),2) + pow((p2.y-p1.y),2) );
    
    if(result<0) result *= -1; 
 
    return result;
}

Ponto proximo(Ponto ordinaryPoints[], int n, Ponto pointToVerify){
    
    Ponto maisProximo;
    float distanciaMaisProxima = INT_MAX;
    
    for(int i=0; i<n; i++){
        
        if(distancia(pointToVerify, ordinaryPoints[i]) < distanciaMaisProxima){
          
          distanciaMaisProxima = distancia(pointToVerify, ordinaryPoints[i]);
          maisProximo = ordinaryPoints[i];
       
        } 
        
    }
   
    return maisProximo;
}

int main(){
    
    int n;
    scanf("%d", &n);
    
    Ponto ordinaryPoints[n];
    for(int i=0; i<n; i++) scanf("%f %f", &ordinaryPoints[i].x, &ordinaryPoints[i].y);
    
    Ponto pointToVerify;
    scanf("%f %f", &pointToVerify.x, &pointToVerify.y);
    
    Ponto pontoMaisProximo = proximo(ordinaryPoints, n, pointToVerify);
    
    printf("%.2f %.2f", pontoMaisProximo.x, pontoMaisProximo.y);
    
    
    return 0;
}