#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;


int main(){
    
    //cout << "Forneça o tamanho do VetorA: " <<endl;
    int n;
    cin >> n;
    stack<int> notUsedPos;
    int vec[n], foundIndexes[n];

    //cout << "Forneça os elementos do VetorA: " <<endl;
    for(int i=0; i<n; i++)
        cin>>vec[i];
    
    //percorre-se ao contrário já que pilha está sendo usada
    for(int i=n-1; i>=0; i--){
        
        //tira da pilha os índices que são menores ou iguais ao número que tá sendo verificado
        if(!notUsedPos.empty())
            while(!notUsedPos.empty() && vec[notUsedPos.top()] <= vec[i])
                notUsedPos.pop();
            
        if(notUsedPos.empty())
            foundIndexes[i] = -1;
        else    
            foundIndexes[i] = notUsedPos.top();
         
        notUsedPos.push(i);
    }
    
    //cout <<endl << "IMPRIMINDO PROXÍMO MAIOR" <<endl; 
    for (int i = 0; i < n; i++){
        if(i == n-1)
            cout<< foundIndexes[i];
        else
            cout<< foundIndexes[i] << " ";
    }
        
    
    //há uma quebra de linha nos finais dos casos de teste    
    cout << endl;
    
    return 0;
}
