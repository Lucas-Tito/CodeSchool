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


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    
    //tratamento caso alguma das listas sejam nulas    
    if (!l1)
        return l2;
    if (!l2)
        return l1;
  
    //começa com a lista que tem a head com o menor valor
    if (l1->val < l2->val){
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else 
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }

}

ListNode* readList(){
    int n;
    cin >> n;
    ListNode * head = nullptr;
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


int main(){
    
    ListNode * list1 = readList();
    ListNode * list2 = readList();
    ListNode * head = mergeTwoLists(list1, list2);

    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << endl;
    
    return 0;    
}
