#include <iostream>
#include <vector>
#include <cassert>
#include <stdbool.h>

using namespace std;

class ListNode {
    public:

    int val;
    ListNode *next;
    
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {} 
};

 

ListNode* populateList(){

    int n;
    cin >> n;
    ListNode * head;
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

    return head;

}


ListNode * insert_back(ListNode ** head, int val){
    
    //it's created a node which will be inseted in the end
    ListNode * new_node = new ListNode(); 
    new_node->val = val;  
    new_node->next = NULL;  
    
    //last it's used to go through the list 
    ListNode *last = *head; 
    
    //if the list is empty, the new node is putted in head
    if (*head == NULL){  
        *head = new_node;  
        return *head;  
    }  
    
    //searchs for the last ellement of the list
    while (last->next != NULL)
        last = last->next;  
    
    //insert a new node after the last node of the list 
    last->next = new_node;  
    
    return *head;  
}


ListNode * intersectionList(ListNode * head1, ListNode * head2){

    ListNode * intersectionList = nullptr;
    
    //compare which element from vector1 with which element of vector2
    for(ListNode* ptr1 = head1; ptr1!=nullptr; ptr1 = ptr1->next)
        for(ListNode* ptr2 = head2; ptr2!=nullptr; ptr2 = ptr2->next)
            if(ptr1->val == ptr2->val){     //if a element which is part of the intersection is found
                
                //if the list of intersection is null
                if(intersectionList != nullptr){
                    
                    bool elementAlreadyInInstersection = false;
                    
                    //verifys if the element to be inserted is already on intersection list
                    for(ListNode* ptr3 = intersectionList; ptr3!=nullptr; ptr3 = ptr3->next)
                        if(ptr3->val == ptr2->val){
                            elementAlreadyInInstersection = true;
                            break;
                        }
                    
                    //if the element isn't on the intersection list, the element is added
                    if(!elementAlreadyInInstersection){
                        insert_back(&intersectionList, ptr2->val);
                        break;
                    }
                        
                }
                //if the intersection list is null, you just need to add
                else{
                    insert_back(&intersectionList, ptr2->val);
                    break;
                }
                    
                
            }
        
        
    return intersectionList;

}


void printList(ListNode * head){
    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << endl;
}



int main(){
    
    ListNode * head1 = populateList();
    ListNode * head2 = populateList();
     
    ListNode * res = intersectionList(head1, head2);


    printList(res);

    return 0;    
}
