#include<stdio.h>

int main(){

    //--------------------------------------------------------+  
    printf("Enter how many elements groupA will have: ");   //|
    int n1;                                                 //|
    scanf("%d", &n1);                                       //|
    printf("Enter groupA elements: \n");                    //|
    int group1[n1];                                         //|
    for(int i=0; i<n1; i++)                                 //|
        scanf("%d", &group1[i]);                            //|
                                                            //| DECLARATION AND ASSAIGNMENT OF ARRAYS
    printf("Enter how many elements groupB will have: ");   //|
    int n2;                                                 //|
    scanf("%d", &n2);                                       //|
    printf("Enter groupB elements: \n");                    //|
    int group2[n2];                                         //|
    for(int i=0; i<n2; i++)                                 //|
        scanf("%d", &group2[i]);                            //|
    //--------------------------------------------------------+ 


      /* DECLARATION OF INTERSECTION ARRAY */
    int max_inter= (n1>=n2 ? n1 : n2);  //determine the max quantity possible for intersection elements
    int inter[max_inter];
    int n_inter =0; //will receive the actual quantity of elements of intersection array
    

        /* PROCESS */    
    for(int i=0; i<n1; i++){
        int containedEquals=0;
        for (int k=0; k<n2; k++){
            if(group1[i]==group2[k]){
                containedEquals=1;
                break;
            } 
        }
        if(containedEquals){
            inter[n_inter] = group1[i];
            n_inter++;              
        }
    }

    /* OUTPUT */

    printf("\nThese are the intersection elements: \n");
    for(int i=0; i<n_inter; i++) printf("%d ", inter[i]);
    
    
    return 0;
}