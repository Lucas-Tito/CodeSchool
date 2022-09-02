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



ListNode * insert_back(ListNode ** head, int val){
    
    //it's created a node that will be inserted on the end
    ListNode * new_node = new ListNode(); 
    new_node->val = val;  
    new_node->next = NULL;  
    
    //last is used to go through the list 
    ListNode *last = *head; 
    
    //if the list is empty, the new node is putted into head
    if (*head == NULL){  
        *head = new_node;  
        return *head;  
    }  
    
    //searchs for the last element on the list
    while (last->next != NULL)
        last = last->next;  
    
    //insert new node after last node on the list 
    last->next = new_node;  
    
    return *head;  
}



ListNode* oddEvenList(ListNode* head, int n){
    
    int count =0;
    ListNode * even=nullptr;
    ListNode * odd=nullptr;
    
    //keeps the values of the odd and even indexes in their respectives lists
    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next){
        if(count % 2 == 0)
            insert_back(&even, ptr->val);
        else
            insert_back(&odd, ptr->val);

        count++;
    }
    
    /*TEST
    cout<< endl << "THIS IS THE ODD VECTOR" << endl;
    for(ListNode * ptr = odd; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << endl;
        
    cout<< endl << "THIS IS THE EVEN VECTOR" << endl;
    for(ListNode * ptr = even; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << endl;
    */
    
    head = nullptr;     //clears list
    
    //insert even values into head
    for(ListNode * ptr = even; ptr != nullptr; ptr = ptr->next)
       insert_back(&head, ptr->val);
    
    //insert odd values into head
    for(ListNode * ptr = odd; ptr != nullptr; ptr = ptr->next)
       insert_back(&head, ptr->val);
        

    return head;
}


int main(){
    int n;
    ListNode * head= nullptr;
    cin >> n;
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

    head = oddEvenList(head, n);
    
    /*TESTE
    cout << endl << "THIS IS THE FINAL VECTOR" << endl;
    */
    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << endl;
    
    return 0;    
}
