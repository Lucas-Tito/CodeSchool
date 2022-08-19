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


int iesimoTermo(ListNode * head, int k){
    
    if(k == 0){
        return head->val;
    }else{
        return iesimoTermo(head->next, k-1);
    }

}


int sizeList(ListNode * head){
    
    int count = 0;
    
    while(head != nullptr){
        head = head->next;
        count++;
    }
        
    return count;
    
}


int getMiddle(ListNode *head){
    
    int n = sizeList(head);
    return iesimoTermo(head, n/2);
    
}    



int main(){
    
    ListNode * head = populateList();
    
    cout << getMiddle(head) << endl;

    
    return 0;    
}
