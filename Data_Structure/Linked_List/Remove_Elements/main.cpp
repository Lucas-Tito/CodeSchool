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
 *head is the first element of a linked list
 *tail is the last one
*/
    
    //while the value in head is equal to val 
    while(head != NULL && head->val == val)
        head = head->next;  //head now points to one element after of the value it pointed before
    
    ListNode * curr = head; //stores the current value that is being verified
    
        
    while(curr != NULL && curr->next != NULL){
        
        //if the value of the current node is equal to val, the node is deleted
        if(curr->next->val == val)
            curr->next = curr->next->next;
        //else we advance one node
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
