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
    Node * root;
    BTree(){
        this->root = nullptr;
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

    BTree(string serial){
        stringstream ss(serial);
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

    string find_path(int value) {
        
    string caminho = _find_path(root,value);
    if (caminho.empty()) {
        return "!";
    }
    return caminho;;
    
    }

    string _find_path(Node * node, int value){
        string line, aux;

        if (node == nullptr) { return "!"; }
        if (node->value == value) { return "x"; }
    
        line = "l" + _find_path(node->left,value);
        aux = line.back();
        if (aux == "x") {
            return line;
        }
        line.pop_back();
        if (node->left == nullptr) { line.pop_back(); }
    
        line = "r" + _find_path(node->right,value);
        aux = line.back();
        if (aux == "x") {
            return line;
        }
        line.pop_back();
        if (node->right == nullptr) { line.pop_back(); }
    
        return line;
    }
};

int main(){
    string line;
    getline(cin, line);
    BTree bt(line);
    int value;
    cin >> value;
    string path = bt.find_path(value);
    cout << path << "\n";
}
