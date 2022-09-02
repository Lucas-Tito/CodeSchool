#include<stdio.h>

int calcPow(int base, int power){
    
    int Pow=0;
    
    if(power==0) return 1;
    else Pow = base*calcPow(base, power-1);
    
    return Pow;

}

int main(){
    
<<<<<<<< HEAD:Programming_Fundamentals/SemanaFunções_+_FunçõesRecursivas/RecursiveFunctionPow/recursive_function_pow.c
    printf("Inform base and power: ");
    int base, power;
    scanf("%d %d", &base, &power);
    
    printf("\nThis is the result: ");
========
    printf("Enter base and power: \n");
    int base, power;
    scanf("%d %d", &base, &power);
    
    printf("The result is: ");
>>>>>>>> 16b5f7adcce502a70a0eb51664f76bfab63f9a27:Programming_Fundamentals/RecursiveFunctionNFunctions_Week/PowRecursiveFunction/pow_recursive_function.c
    printf("%d", calcPow(base, power));
    
    
    return 0;
}