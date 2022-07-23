#include <iostream>
#include <sstream>
using namespace std;

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

    void __destroy(Node * node){
        if(node == nullptr)
            return;
        __destroy(node->left);
        __destroy(node->right);
        delete node;
    }

    ~BTree(){
        __destroy(this->root);
    }
    
    void showAux(Node * root, int nivel){ 
        if(root == nullptr){
            for( int i = 0; i < nivel; i++){
            cout << "....";
            }
            cout  << "#" << endl;
            return;
        }
        if(root -> left != nullptr || root -> right != nullptr){
        showAux(root -> left ,  nivel + 1);
        }
        
        for( int i = 0; i < nivel; i++){
            cout << "....";
        }

        cout  << root -> value << endl;

        if(root -> left != nullptr || root -> right != nullptr){
        showAux(root -> right, nivel + 1);
        }
    }
    void show(){
        showAux(root, 0);
    }

};



int main(){
    string lineToRead;
    getline(cin, lineToRead);
    BTree bt(lineToRead);
    bt.show();
}
