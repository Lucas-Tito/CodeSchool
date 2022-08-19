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



ListNode* oddEvenList(ListNode* head, int n){
    
    int count =0;
    ListNode * par=nullptr;
    ListNode * impar=nullptr;
    
    //guarda os valores dos índices ímpares e pares em suas respectivas listas
    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next){
        if(count % 2 == 0)
            insert_back(&par, ptr->val);
        else
            insert_back(&impar, ptr->val);

        count++;
    }
    
    /*TESTE
    cout<< endl << "ESTE É O VETOR DE ÍMPARES" << endl;
    for(ListNode * ptr = impar; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << endl;
        
    cout<< endl << "ESTE É O VETOR DE PARES" << endl;
    for(ListNode * ptr = par; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << endl;
    */
    
    head = nullptr;     //limpa a lista
    
    //insere os valores pares em head
    for(ListNode * ptr = par; ptr != nullptr; ptr = ptr->next)
       insert_back(&head, ptr->val);
    
    //insere os valores impares em head
    for(ListNode * ptr = impar; ptr != nullptr; ptr = ptr->next)
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
    cout << endl << "ESTE É O VETOR FINAL" << endl;
    */
    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << endl;
    
    return 0;    
}
