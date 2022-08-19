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
    
    // é criado o nó que será inserido no final
    ListNode * new_node = new ListNode(); 
    new_node->val = val;  
    new_node->next = NULL;  
    
    // last é usado para percorrer a list 
    ListNode *last = *head; 
    
    //se a lista for vazia, o novo nó é posto em head
    if (*head == NULL){  
        *head = new_node;  
        return *head;  
    }  
    
    //procura pelo último elemento da lista
    while (last->next != NULL)
        last = last->next;  
    
    //insere o novo nó depois do último nó da lista 
    last->next = new_node;  
    
    return *head;  
}


ListNode * intersectionList(ListNode * head1, ListNode * head2){

    ListNode * intersectionList = nullptr;
    
    //compara cada elemento do vetor 1 com cada elemento do vetor 2
    for(ListNode* ptr1 = head1; ptr1!=nullptr; ptr1 = ptr1->next)
        for(ListNode* ptr2 = head2; ptr2!=nullptr; ptr2 = ptr2->next)
            if(ptr1->val == ptr2->val){     //se um elemento que faz parte da interseção for encontrado
                
                //se a lista dos elementos da interseção for nula
                if(intersectionList != nullptr){
                    
                    bool elementAlreadyInInstersection = false;
                    
                    //verifica se o elemento a ser inserido já está na lista de interseções
                    for(ListNode* ptr3 = intersectionList; ptr3!=nullptr; ptr3 = ptr3->next)
                        if(ptr3->val == ptr2->val){
                            elementAlreadyInInstersection = true;
                            break;
                        }
                    
                    //se o elemento já não estiver na lista de interseção, este é adicionado
                    if(!elementAlreadyInInstersection){
                        insert_back(&intersectionList, ptr2->val);
                        break;
                    }
                        
                }
                //se a lista de interseção estiver vazia, é só adicionar
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
