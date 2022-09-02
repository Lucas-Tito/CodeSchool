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
    
    //a node is created to be inserted into the end
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
    
    //searchs for the last list element
    while (last->next != NULL)
        last = last->next;  
    
    //insert the new node after the last node 
    last->next = new_node;  
    
    return *head;  
}


void print_list(ListNode * head){

    for(auto ptr = head; ptr != nullptr; ptr = ptr->next){
        cout << ptr->val << endl;
    }

}


ListNode * reverseList(ListNode * head){

    if(head == nullptr || head->next == nullptr) //handling for the empty list or with size 1
        return head;
        
    else{
        ListNode * ptr; //used to go through list
        int valor = head->val;
        ptr = reverseList(head->next);
        delete head;
        return insert_back(&ptr, valor);
    }
}





/*
 * Function created to count the occurrences of 9
 * after the node given in parameter
*/
int howMany9sAfter(ListNode * head){
    
    int howMany = 0; 
    
    for(ListNode * ptr = head; ptr->next != nullptr; ptr = ptr->next){
        
        if(ptr->next->val == 9)
            howMany++;
    
    }
    
    return howMany;
}


ListNode* someUm(ListNode *head){
    
    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next){

        if(ptr->val != 9){
            ptr->val+=1;
            break;
        }
        
        //if value is equal to 9    
        else{
            int qtdDeNoves = howMany9sAfter(ptr);

            //if there isn't any nine after the current nine
            if(qtdDeNoves == 0){
               
                //if only one node exists after the current node
                if(ptr->next != nullptr){
                    ptr->val = 0;
                    ptr->next->val+=1;
                    break; 
                }
                //else it's necessary to create a new node
                else{
                    ptr->val = 0;
                    insert_back(&head, 1);
                    break;
                }
            }
            //if there is one or more nines after the current nine
            else
                ptr->val = 0;
            
        }
    }
    
    return head;
} 


int main(){
    
    ListNode * head = populateList();
    head = reverseList(head);  //inverts the list 
    head = someUm(head);

    head = reverseList(head);  //undo invert
    print_list(head);
    
    return 0;    
}
