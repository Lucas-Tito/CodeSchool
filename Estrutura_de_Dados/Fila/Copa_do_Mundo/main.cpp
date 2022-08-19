#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<queue>

using namespace std;

/*
typedef struct{
    
    int front=0, back=-1;   //geralmente back começa como -1
    
    char queue [16] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                        'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P' };
    
    bool isFull(){
        
        if(back==15)
            return true;
        else
            return false;
        
    }
    
    bool IsEmpty(){
        if(front>back)
            return true;
        else
            return false;
    }
    
    void addElement(char x){ //adiciona no final
        
        if(!isFull()){
            back++;
            queue[back]=x;
        }
        
    }
    
    void removeElement(){ //remove do começo
        
        if(!IsEmpty())
            front++;    //o valor não chega a ser removido, só que passa a ser ignorado
        
    }
    
    int getQueueElement(){  //retorna o valor no início da fila
        
        return queue[front];
        
    }
    
    void printQueue(){
        
        cout << "--------IMPRIMINDO FILA--------"<<endl;
        for(int i=front; i<back; i++)
            printf("%c ", queue[i]);
        cout << endl <<"-------------------------------" <<endl;
        
    }
    
} Queue;
*/

int main(){
    
    queue<char> resultados;
    char values [16] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                        'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P' };
    for(int i =0; i<16; i++)
        resultados.push(values[i]);
    
    int result1, result2;
    char winner;
    
    while(resultados.size()>1){
        
        cin >> result1 >> result2;
        
        if(result1>result2){
            winner = resultados.front();
            resultados.pop();
            resultados.pop();
            resultados.push(winner);
        }
        else{
            resultados.pop();
            winner = resultados.front();
            resultados.pop();
            resultados.push(winner);
        }
            
    }
    
    printf("%c\n", resultados.front());

    return 0;
}
