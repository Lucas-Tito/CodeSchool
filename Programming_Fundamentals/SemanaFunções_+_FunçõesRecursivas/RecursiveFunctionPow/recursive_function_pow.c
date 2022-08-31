#include<stdio.h>

int calcPow(int base, int power){
    
    int Pow=0;
    
    if(power==0) return 1;
    else Pow = base*calcPow(base, power-1);
    
    return Pow;

}

int main(){
    
    printf("Inform base and power: ");
    int base, power;
    scanf("%d %d", &base, &power);
    
    printf("\nThis is the result: ");
    printf("%d", calcPow(base, power));
    
    
    return 0;
}