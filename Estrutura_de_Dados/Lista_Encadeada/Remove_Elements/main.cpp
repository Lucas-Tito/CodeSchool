#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class ListNode {
    public:

    int val;
    ListNode *next;
    
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {} 
};

ListNode* removeElements(ListNode* head, int val) {
    
/*
 *head é o primeiro elemento de uma lista encadeada
 *já tail, é o último elemento de uma lista encadeada
*/
    
    //enquanto o valor em head for equivalente a val 
    while(head != NULL && head->val == val)
        head = head->next;  // head passa a apontar para 1 depois do que esta apontava antes
    
    ListNode * curr = head; //armazena o valor atual que está sendo verificado da lista encadeada
    
        
    while(curr != NULL && curr->next != NULL){
        
        //if o valor do nó atual seja equivalente a val, este nó é deletado
        if(curr->next->val == val)
            curr->next = curr->next->next;
        //se não avançamos um nó
        else
            curr = curr->next;
        
        
    }
      
    return head;
}



int main(){
    
    int n, val;
    ListNode * head= nullptr;
    cin >> n >> val;
    
    for(int i = 0; i < n; i++){
        
        ListNode * ptr;
        int x;
        cin >> x;
        if( i == 0){
            head = new ListNode(x);
            ptr = head;
        }else{
            ptr->next = new ListNode(x, nullptr);
            ptr = ptr->next;
        }
        
    }
        
    head = removeElements(head, val );

    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << endl;
    
    return 0;    
    
}
