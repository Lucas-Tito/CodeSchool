#include <iostream>
#include <sstream>
#include <queue>
using namespace std;


/*              BASIC FUNCTIONS THAT I DEVELOIPED TO UNDERSTAND BINARY TREE
class Node{
    
    private:
       Node *left, *right;
       int key;
       
    public:
        Node(int keyToAdd){
            
            key = keyToAdd;
            left = NULL;
            right = NULL;
            
        }
        
        int getKey(){
            return key;
        }
        
        Node* getLeft(){
            return left;
        }
        
        Node* getRight(){
            return left;
        }
        
        void setLeft(Node* node){
            left = node;
        }
        
        void setRight(Node* node){
            right = node;
        }
        
}

class Tree{
    
    private: 
        Node* root;
    
    public:
        Arvore(){
            root = NULL;
        }
        
        void insert(int key){
            if(root == NULL)
                root = new Node(key);
            else
                insertAux(root, key)
        }
        
        insertAux(Node* node, int key){
            
            if(key < node->getChave()){     //if the value is smaller than the node, it's inserted at left.
                if(node->getLeft() == NULL){
                    
                    Node* new_node = new Node(key);
                    node->setLeft(new_node);
                    
                }
                else    //if current node has a node at left
                    insertAux(node->getLeft(), key)
            }                                       
            else if(key > node->getKey()){  //if value is greater than the one in the node, it's inserted at right
                if(node->getRight() == NULL){
                    
                    Node* new_node = new Node(key);
                    node->setRight(new_node);
                    
                }
                else
                    insertAux(node->getLeft(), key);
            }
                
        }
        
        Node* getRoot(){
            return root;
        }
        
        
};
*/


struct Node{
    int value;
    Node * left;
    Node * right;
    Node(int value = 0, Node * left = nullptr, Node * right = nullptr){
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

struct BTree{
    Node * root {nullptr};
    BTree(){
    }

    void clone(stringstream& ss, Node ** elo){
        string value;
        ss >> value;
        if(value == "#")
            return;
        int num;
        stringstream(value) >> num;
        *elo =  new Node(num);
        clone(ss, &(*elo)->left);
        clone(ss, &(*elo)->right);
    }

    BTree(string line){
        stringstream ss(line);
        clone(ss, &root);
    }

    ~BTree(){ //tree destructor
        __destroy(this->root);
    }

    void __destroy(Node * node){
        if(node == nullptr)
            return;
        __destroy(node->left);
        __destroy(node->right);
        delete node;
    }
    
    void bshow(){
        __bshow(this->root);
    }

    void __bshow(Node * node, string heritage = ""){
        if(node != nullptr && (node->left != nullptr || node->right != nullptr))
            __bshow(node->left , heritage + "l");
        for(int i = 0; i < (int) heritage.size() - 1; i++)
            cout << (heritage[i] != heritage[i + 1] ? "│   " : "    ");
        if(heritage != "")
            cout << (heritage.back() == 'l' ? "┌───" : "└───");
        if(node == nullptr){
            cout << "#" << endl;
            return;
        }
        cout << node->value << endl;
        if(node != nullptr && (node->left != nullptr || node->right != nullptr))
            __bshow(node->right, heritage + "r");
    }

    void show_in_order(){
        cout << "[ ";
        __show_in_order(root);
        cout << "]\n";
    }

    void __show_in_order(Node * node){
        if(node == nullptr)
            return;
        __show_in_order(node->left);
        cout << node->value << " ";
        __show_in_order(node->right);
    }

};

int main(){
    string lineToRead;
    getline(cin, lineToRead);
    BTree bt(lineToRead);
    bt.show_in_order();
}
