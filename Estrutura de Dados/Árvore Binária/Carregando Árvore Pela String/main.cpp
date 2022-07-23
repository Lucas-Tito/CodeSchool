#include <iostream>
#include <sstream>
#include <queue>
using namespace std;


/*              FUNÇÕES BÁSICAS QUE DESENVOLVI PRA ENTENDER BIN TREE
class Node{
    
    private:
       No *left, *right;
       int key;
       
    public:
        No(int keyToAdd){
            
            key = keyToAdd;
            left = NULL;
            right = NULL;
            
        }
        
        int getKey(){
            return key;
        }
        
        No* getLeft(){
            return left;
        }
        
        No* getRight(){
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
        
        void inserir(int key){
            if(root == NULL)
                root = new Node(key);
            else
                inserirAux(root, key)
        }
        
        inserirAux(Node*  node, int key){
            
            if(key < node->getChave()){     //se o valor for menor que o do nó, é inserido a esquerdo
                if(node->getLeft() == NULL){
                    
                    Node* new_node = new Node(key);
                    node->setLeft(new_node);
                    
                }
                else    //se o nó atual tiver um nó a esquerda
                    inserirAux(node->getLeft(), key)
            }                                       
            else if(key > node->getKey()){  //se o valor for maior que o do nó, é inserido a direita
                if(node->getRight() == NULL){
                    
                    Node* new_node = new Node(key);
                    node->setRight(new_node);
                    
                }
                else
                    inserirAux(node->getLeft(), key);
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

    ~BTree(){ //destrutor da árvore
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

    void __bshow(Node * node, string heranca = ""){
        if(node != nullptr && (node->left != nullptr || node->right != nullptr))
            __bshow(node->left , heranca + "l");
        for(int i = 0; i < (int) heranca.size() - 1; i++)
            cout << (heranca[i] != heranca[i + 1] ? "│   " : "    ");
        if(heranca != "")
            cout << (heranca.back() == 'l' ? "┌───" : "└───");
        if(node == nullptr){
            cout << "#" << endl;
            return;
        }
        cout << node->value << endl;
        if(node != nullptr && (node->left != nullptr || node->right != nullptr))
            __bshow(node->right, heranca + "r");
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
