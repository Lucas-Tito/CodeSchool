#include<iostream>
#include<stack>
#include<stdbool.h>

using namespace std;


struct pilha {
    
    int count=0;
    stack<int> storage;
    stack<int> mimValue;
    
    void push(int x){
        storage.push(x);
        
        if(count==0)
            mimValue.push(x);
        else
            if(mimValue.top()>x)
                mimValue.push(x);
        
        count++;
    }
    
    void pop(){
        if(mimValue.size()>1)
            mimValue.pop();
    }
    
    int getMin(){
        return mimValue.top();
    }
    
} typedef pilha;


int main(){
    int n;
    cin >> n;
    pilha A;
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
