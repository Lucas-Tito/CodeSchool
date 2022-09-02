#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

struct Operation{   //Create a type to better understand the code
    int type;
    int value;
};

//GIVEN THAT IS NECESSARY TO SORT AFTER EACH INSERT, THE INSERTION SORT IS BETTER OPTMIZED TO THIS APPLICATION

void insertionSort(int* vector, int n){
    /*
     *j always keeps the position before the current one
     *key keeps the current element
    */
    int key, j;    
    for (int i = 1; i < n; i++){
        key = vector[i];
        j = i - 1;
        
        while (j >= 0 && vector[j] > key){
            
            vector[j + 1] = vector[j];    //moves element greater than key to after current position
            j--;
            
        }
        vector[j + 1] = key;
    }
}


int main(){

    int n, count=0;
    cin >> n;
    int vector[n];  
    Operation op;

    for(int i=0; i<n; i++){     //receive operations and values
        cin >> op.type;
        cin >> op.value;

        if(op.type == 2){
            cout << vector[op.value] << endl;
        }       
        else{
            vector[count]=op.value;    //adds value to vector when operation is equal to 1
            count++;
            insertionSort(vector, count); //passes count to sort only what's being populated so far   
        }

    }
    
    return 0;
}
