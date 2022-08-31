#include<stdio.h>

typedef struct{
  int day, month, year;
}BirthDate;



//function to determine if the person already had birthday this year
int isFullYear(BirthDate birth, int current_date[]){           
    
    int isFullYear=0;
    if (birth.month - current_date[1] <=0){

        if(birth.day - current_date[0] >0){

            if(birth.month - current_date[1] ==0)
                isFullYear=0;
            else 
                isFullYear=1;

        }
        else if(birth.day - current_date[0] <=0)
             isFullYear=1;

        else if(birth.month - current_date[1] <0){

            if(birth.day - current_date[0] >0){
                if(birth.month - current_date[1] ==0)
                    isFullYear=0;
                else 
                    isFullYear=1;
            }

        }

    }
    else isFullYear=0;
    
    return isFullYear;
}



int OlderOne(BirthDate array[], int n, int current_date[]){      
    
    int olderOne= -1, age=0;

    for(int i=0; i<n; i++){
        
        if(isFullYear(array[i], current_date)) 
            age = current_date[2] - array[i].year;
        else 
            age = current_date[2] - array[i].year -1;
        
        if(age>olderOne) olderOne = age;
         
    }
    
    return olderOne;
}




int main(){
    
    /* INPUT */
    printf("Enter how many people will be compared: \n");
    int n;
    scanf("%d", &n);
    
    printf("Enter their BirthDate: \n");
    BirthDate people[n];
    for(int i=0; i<n; i++) 
        scanf("%d %d %d", &people[i].day, &people[i].month, &people[i].year);
    
    printf("Enter current date: (separate by spaces)\n");
    int current_date[3];
    scanf("%d %d %d", &current_date[0], &current_date[1], &current_date[2]);
    

    /* PROCESS */
    printf("\nThis is the older age: ");
    printf("%d", OlderOne(people, n, current_date));
    
    
    return 0;
}