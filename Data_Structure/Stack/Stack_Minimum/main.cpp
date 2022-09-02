#include<iostream>
#include<stack>
#include<stdbool.h>

using namespace std;


struct stack {
    
    int count=0;
    stack<int> storage;
    stack<int> minValue;
    
    void push(int x){
        storage.push(x);
        
        if(count==0)
            minValue.push(x);
        else
            if(minValue.top()>x)
                minValue.push(x);
        
        count++;
    }
    
    void pop(){
        if(minValue.size()>1)
            minValue.pop();
    }
    
    int getMin(){
        return minValue.top();
    }
    
} typedef stack;


int main(){
    int n;
    cin >> n;
    stack A;
    int operation, elementToAdd;
    for(int i=0; i<n; i++){
        cin >> operation;

        switch (operation){
            case 1:
                cin>>elementToAdd;
                A.push(elementToAdd);
                break;
            case 2:
                A.pop();
                break;
            case 3:
                cout << A.getMin() << endl;
                break;
        }
            
    }
    
    return 0;
}
