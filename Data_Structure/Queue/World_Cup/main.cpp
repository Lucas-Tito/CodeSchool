#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<queue>

using namespace std;

/*
typedef struct{
    
    int front=0, back=-1;   //generely back starts with -1
    
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
    
    void addElement(char x){ //adds to the end
        
        if(!isFull()){
            back++;
            queue[back]=x;
        }
        
    }
    
    void removeElement(){ 
        
        if(!IsEmpty())
            front++;    //the value isn't actualy remove, just ignored
        
    }
    
    int getQueueElement(){  //returns the value in the begining of queue
        
        return queue[front];
        
    }
    
    void printQueue(){
        
        cout << "--------PRINTING QUEUE--------"<<endl;
        for(int i=front; i<back; i++)
            printf("%c ", queue[i]);
        cout << endl <<"-------------------------------" <<endl;
        
    }
    
} Queue;
*/

int main(){
    
    queue<char> results;
    char values [16] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                        'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P' };
    for(int i =0; i<16; i++)
        results.push(values[i]);
    
    int result1, result2;
    char winner;
    
    while(results.size()>1){
        
        cin >> result1 >> result2;
        
        if(result1>result2){
            winner = results.front();
            results.pop();
            results.pop();
            results.push(winner);
        }
        else{
            results.pop();
            winner = results.front();
            results.pop();
            results.push(winner);
        }
            
    }
    
    printf("%c\n", results.front());

    return 0;
}
