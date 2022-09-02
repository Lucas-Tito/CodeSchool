#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;


int main(){
    
    //cout << "Enter the size of VectorA: " <<endl;
    int n;
    cin >> n;
    stack<int> notUsedPos;
    int vec[n], foundIndexes[n];

    //cout << "Enter VectorA elements: " <<endl;
    for(int i=0; i<n; i++)
        cin>>vec[i];
    
    //Go through the stacke in reverse given that the stack is being used
    for(int i=n-1; i>=0; i--){
        
        //remove from stack the indexes smaller or equal to the number being verified
        if(!notUsedPos.empty())
            while(!notUsedPos.empty() && vec[notUsedPos.top()] <= vec[i])
                notUsedPos.pop();
            
        if(notUsedPos.empty())
            foundIndexes[i] = -1;
        else    
            foundIndexes[i] = notUsedPos.top();
         
        notUsedPos.push(i);
    }
    
    //cout <<endl << "PRINTING NEXT GREATER" <<endl; 
    for (int i = 0; i < n; i++){
        if(i == n-1)
            cout<< foundIndexes[i];
        else
            cout<< foundIndexes[i] << " ";
    }
    
    cout << endl;
    
    return 0;
}
