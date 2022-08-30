#include<stdio.h>
#include<stdlib.h>

int binnarySearch(int item){
    
    int low=0, high=1000000, attempts=0, mid;
    
    while(low <= high){
        
        attempts++;
        mid = (low + high)/2;    //calc mid
        
        if(mid == item)     //if item is on mid, while stops
            break;         
        /*
         *Given that the group is ordered, if mid is greater than item
         *High become mid -1 (as if all elements after mid were discarted)
         *Since these elements are greater than item too
        */ 
        else
            if(mid > item)  
                high = mid - 1;     
        else                         
            low = mid + 1;  //if mid is smaller than item, the approach is the same, but this time all the smaller elements are discarted
    }
    printf("\nend number = %d\n", mid);
    return attempts;   
}


int main(){
   
        /* INPUT */
    printf("Enter a number between 0 and 1000000: ");
    int userNumber;
    scanf("%d", &userNumber);

        /* PROCESS */
    if(userNumber<0 && userNumber> 1000000)
        printf("\nerror:invalid number provided\n")
    
    else{
        int attempts = binnarySearch(userNumber);
        printf("The computer needed %d attempts to guess your number", attempts);
    }


    return 0;
}