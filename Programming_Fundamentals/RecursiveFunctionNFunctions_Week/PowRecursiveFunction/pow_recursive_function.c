#include<stdio.h>

int calcPow(int base, int power){
    
    int Pow=0;
    
    if(power==0) return 1;
    else Pow = base*calcPow(base, power-1);
    
    return Pow;
}

int main(){
    
    printf("Enter base and power: \n");
    int base, power;
    scanf("%d %d", &base, &power);
    
    printf("The result is: ");
    printf("%d", calcPow(base, power));
    
    
    return 0;
}