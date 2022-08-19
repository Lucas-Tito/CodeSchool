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

ListNode* deleteDuplicates(ListNode* head) {
    ListNode * ptr = head;
    ListNode * ptr2 = nullptr;
    
    while(ptr != nullptr && ptr->next != nullptr){  //verifica se a lista está vazia
        ptr2 = ptr;
        
        while(ptr2->next != nullptr){       
            //se elemento atual é igual ao proximo, o valor do próximo é deletado
            if(ptr->val == ptr2->next->val){    
                ListNode * aux = ptr2->next;    
                ptr2->next = ptr2->next->next;  
                delete aux;                     
            }else{
                ptr2 = ptr2->next; //se a condição for falsa o segundo ponteiro é incrementado
            }
        }
        ptr = ptr->next;    //incrementado quando nenhum elemento é igual ao termo atual
    }
        
            
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

    head = deleteDuplicates(head);
    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << endl;
    
    return 0;    
}
