#include <stdio.h>

int main(){
    
    //----------------------------+ 
    int n1;                     //|
    scanf(%d, &n1);             //|
    int group1[n1];             //|
    for(int i=0; i<n1; i++)     //|
        scanf(%d, &group1[i]);  //|   declaration and assignment of arrays
                                //|
    int n2;                     //|
    scanf(%d, &n2);             //|
    int group2[n2];             //|
    for(int i=0; i<n2; i++)     //|
        scanf(%d, &group2[i]);  //|
    //----------------------------+ 
        
    
    
    int equalElements =0;    
    for(int i=0; i<n1; i++)
        for(int k=0; k<n2; k++)
            if(group1[i]==group2[k]){ 
                equalElements += 1;
                break;
            }
            
            
    if(equalElements == n1) printf("Contained");
    else printf("Not contained");
    
    
    return 0;
}