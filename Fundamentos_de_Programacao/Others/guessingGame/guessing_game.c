#include<stdio.h>
#include<stdlib.h>

int main(){
   
        /* INPUT */
    printf("Enter a number: ");
    int userNumber;
    scanf("%d", &userNumber);
    
        /* PROCESS */
    srand(time(NULL));
    int guessing=0, attempts=0;
   
    do{
         // in the first attempt, the computer guess a random number
        if(attempts==0)  
            guessing = rand() % 1024 + 1;        

        if(guessing>userNumber)
            guessing--;
            
        else if(guessing<userNumber)
            guessing++;
        
        attempts++;
        
    }while(guessing!=userNumber);
    

    printf("The computer needed %d attempts to guess your number", attempts);
    
    return 0;
}