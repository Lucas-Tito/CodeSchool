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


void print_list(ListNode * head){

    for(auto ptr = head; ptr != nullptr; ptr = ptr->next){
        cout << ptr->val << endl;
    }

}


ListNode * reverseList(ListNode * head){

    if(head == nullptr || head->next == nullptr) // tratamento para lista vazia ou de tamanho 1
        return head;
        
    else{
        ListNode * ptr; //usado para percorrer a lista
        int valor = head->val;
        ptr = reverseList(head->next);
        delete head;
        return insert_back(&ptr, valor);
    }
}





/*
 * Função criada para contar as ocorrências do número 9
 * após o nó passado por parâmetro
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
        
        //se o valor for = 9    
        else{
            int qtdDeNoves = howMany9sAfter(ptr);

            //se não há nenhum nove depois do nove atual
            if(qtdDeNoves == 0){
               
                //se existir um nó depois do nó atual
                if(ptr->next != nullptr){
                    ptr->val = 0;
                    ptr->next->val+=1;
                    break; 
                }
                //se não é preciso criar um novo nó
                else{
                    ptr->val = 0;
                    insert_back(&head, 1);
                    break;
                }
            }
            //se há um ou + noves depois do nove atual 
            else
                ptr->val = 0;
            
        }
    }
    
    return head;
} 


int main(){
    
    ListNode * head = populateList();
    head = reverseList(head);  //inverte a lista 
    head = someUm(head);

    head = reverseList(head);  //desinverte a lista
    print_list(head);
    
    return 0;    
}
