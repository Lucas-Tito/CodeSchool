#include<stdio.h>
#include<math.h>

typedef struct{
    
    float x, y;
    
}Ponto;

float distanceCalc(Ponto p1, Ponto p2){
    
    float result = sqrt( pow((p2.x-p1.x),2) + pow((p2.y-p1.y),2) );
    
    return result;
}


int main(){
    
    Ponto p1;
    scanf("%f %f", &p1.x, &p1.y);
    
    Ponto p2;
    scanf("%f %f", &p2.x, &p2.y);
    
    float distancia = distanceCalc(p1, p2); 
    printf("%.2f", distancia);
    
    return 0;
}