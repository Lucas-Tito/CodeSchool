#include<stdio.h>
#include<stdlib.h>

int* merge_arrays(int* array1, int n, int* array2, int m){
    
    int* expanded_array = (int*)malloc((n+m)*sizeof(int));
    
    for(int i=0; i<n; i++) expanded_array[i]=array1[i];
    for(int i=0; i<m; i++) expanded_array[i+n]=array2[i];
    
    free(array1);
    free(array2);
    
    return expanded_array;
    
}

int main(){
    
    /* INPUT */
    printf("Enter how many elements arrayA will have: ");
    int n;
    scanf("%d", &n);
    
    printf("\nEnter arrayA elements: \n");
    int *array1 = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++) scanf("%d", &array1[i]);
    
    printf("\nEnter how many elements arrayA will have: ");
    int m;
    scanf("%d", &m);
    
    printf("\nEnter arrayA elements: \n");
    int *array2 = (int*)malloc(m*sizeof(int));
    for(int i=0; i<m; i++) scanf("%d", &array2[i]);
    
    
    /* PROCESS */
    int* expanded_array = merge_arrays(array1, n, array2, m);
    
    
    /* OUTPUT */
    printf("This is the merged array: ")
    for(int i=0; i<n+m; i++) printf("%d ", expanded_array[i]);
    
    free(expanded_array);
    
    return 0;
}