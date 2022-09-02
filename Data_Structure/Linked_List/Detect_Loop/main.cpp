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
    int n, x;
    cin >> n >> x;
    ListNode * head;
    ListNode * tmp = nullptr;

    ListNode * ptr;
        
    for(int i = 1; i <= n; i++){
        int v;
        cin >> v;
        if( i == 1){
            head = new ListNode(v);
            ptr = head;
        }else{
            ptr->next = new ListNode(v, nullptr);
            ptr = ptr->next;
        }

        if(i == x){
            tmp = ptr;
        }

    }

    
    ptr->next = tmp;
    return head;

}

bool detectLoop(ListNode* head){
    ListNode *slow = head, *fast = head;
  
    //while these guys are different than NULL
    while (slow && fast && fast->next) {
        //slow moves 1
        slow = slow->next;
        //fast moves 2
        fast = fast->next->next;
        
        if (slow == fast) {
            return true;
        }
    }
    return false;
}


int main(){
    
    ListNode * head = populateList();
    
    cout << detectLoop(head) << endl;

    return 0;    
}
