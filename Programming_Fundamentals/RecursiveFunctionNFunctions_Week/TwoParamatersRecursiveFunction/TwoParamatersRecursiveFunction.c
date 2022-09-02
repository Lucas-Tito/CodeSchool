#include<stdio.h>

int calcH(int m, int n){
    
    int h=0;
    
    if(n==1) return m+1;
    else if(m==1) return n+1;
    else if(m>1 && n>1) h = calcH(m, n-1) + calcH(m-1, n);
    
    return h;
}

int main(){
    
    printf("Enter a numberA and B: ");
    int m, n;
    scanf("%d %d", &m, &n);
    
    printf("\nThis is the result of the function: ");
    printf("%d", calcH(m, n));   
    
    return 0;
    
}