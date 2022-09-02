#include<iostream>
using namespace std;

int binarySearch_count(int *vector, int n, int item){
    
    int low=0, high=n-1, count=0, middle;
    
    while(low <= high){
        
        count++;
        middle = (low + high)/2;    //compute middle of vector
        
        if(vector[middle] == item)     //if tne item is on middle, while stops
            break;         
        /*
         *Given that the vector is sorted, if the element on middle is greater than item
         *High becomes middle -1 (is as if all elements after middle were deleted)
         *Because elements after middle are greater than item too
        */ 
        else
            if(vector[middle] > item)  
                high = middle - 1;     
        else                         
            low = middle + 1;  //if element on middle is smaller, the process is the same, but this time the smaller elements are discarted
    }
 
    return count;   
}

void populateVec(int* vec, int n){
    
    for(int i=0; i<n; i++)
        cin >> vec[i];
    
}

int main(){
    
    int nVec, nQuestions;
    cin >> nVec;
    cin >> nQuestions;
    
    int sortedVec[nVec], questionsVec[nQuestions];
    populateVec(sortedVec, nVec);
    populateVec(questionsVec, nQuestions);
      
    for(int i=0; i<nQuestions; i++){
        if(i == nQuestions-1)
            cout <<binarySearch_count(sortedVec, nVec, questionsVec[i]) << endl;
        else
            cout <<binarySearch_count(sortedVec, nVec, questionsVec[i]) << " ";
    }
    
    
    return 0;
}
