#include<stdio.h>
#include<math.h>
#include<limits.h> 
#define pi 3.14         // constante, uma variável que não pode ser modificada

typedef struct{
    
    float x, y, raio;
    
}Circulo;

float calcLargerstArea(Circulo circulos[], int n){
    
    float largestArea = INT_MIN;
    
    for(int i=0; i<n; i++){
        
        float area = pi*pow(circulos[i].raio, 2);
        if(area>largestArea) largestArea = area;
    }
    
    return largestArea;
}



int main(){
    
    int n;
    scanf("%d", &n);
    
    Circulo circulos[n];
    for(int i=0; i<n; i++) scanf("%f %f %f", &circulos[i].x, &circulos[i].y, &circulos[i].raio);
    
    float largestArea = calcLargerstArea(circulos, n);
    
    printf("%.2f", largestArea);
    
    
    
    
    
    
    return 0;
}

