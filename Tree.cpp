#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;

    Node(){
        left = right = nullptr;
    }
};

class binaryTree{
    public:
        Node *root;

    binaryTree(){
        root = nullptr;
    }

    Node *insertBST (int data, Node* currentRoot){
        if ( currentRoot == nullptr ){
            Node* newNode = new Node();
            newNode->data = data;
            return newNode;
        }

        if(data < currentRoot->data){
            currentRoot->left = insertBST(data, currentRoot->left);
        }
        else if(data > currentRoot->data){
            currentRoot->right = insertBST(data, currentRoot->right);
        }

        return currentRoot;
    }

    void insert(int data){
        root = insertBST(data, root);
    }
    //pre order
    Node *preOrderRecursive(Node * currentRoot){
        if(currentRoot != nullptr){
            cout << currentRoot->data << " ";
            preOrderRecursive(currentRoot->left);
            preOrderRecursive(currentRoot->right);
        }
    }

    //in order
    Node *inOrderRecursive(Node * currentRoot){
        if(currentRoot != nullptr){
            inOrderRecursive(currentRoot->left);
            cout << currentRoot->data << " ";
            inOrderRecursive(currentRoot->right);
        }
    }

    //post order
    Node *postOrderRecursive(Node * currentRoot){
        if(currentRoot != nullptr){
            postOrderRecursive(currentRoot->left);
            postOrderRecursive(currentRoot->right);
            cout << currentRoot->data << " ";
        }
    }


    void preOrderTraversal(){
        cout << "Pre Order Traversal : ";
        preOrderRecursive(root);
        cout << endl;
    }

    void inOrderTraversal(){
        cout << "In Order Traversal : ";
        inOrderRecursive(root);
        cout << endl;
    }

    void postOrderTraversal(){
        cout << "Post Order Traversal : ";
        postOrderRecursive(root);
        cout << endl;
    }

    Node * findReplacement(Node *currentRoot){
        currentRoot = currentRoot->right;
        while(currentRoot->left != nullptr){
            currentRoot = currentRoot->left;
        }
        return currentRoot;
    }
        
    Node* deleteNode(int data, Node *currentRoot){
        if(currentRoot == nullptr){
            return currentRoot;
        }

        if(data < currentRoot->data){
            currentRoot->left = deleteNode(data, currentRoot->left);
        }
        else if(data > currentRoot->data){
            currentRoot->right = deleteNode(data, currentRoot->right);
        }
        else{
            if(currentRoot->left == nullptr){
                Node *temp = currentRoot->right;
                delete currentRoot;
                return temp;
            }
            else if(currentRoot->right == nullptr){
                Node * temp = currentRoot->left;
                delete currentRoot;
                return temp;
            }

            Node *temp = findReplacement(currentRoot);
            currentRoot->data = temp->data;
            currentRoot->right = deleteNode(temp->data, currentRoot->right);
        }

        return currentRoot;
    }

    void deleteTree(int data){
        root = deleteNode(data, root);
    }

};

int main () {
    binaryTree bst1;

    bst1.insert(6);
    bst1.insert(7);
    bst1.insert(4);
    bst1.insert(3);
    bst1.insert(5);   
    bst1.insert(8);

    bst1.inOrderTraversal();

    bst1.deleteTree(6);

    bst1.inOrderTraversal();

    bst1.deleteTree(3);

    bst1.inOrderTraversal();

    return 0;
}




    

    /*

    Node * delete_bst(int value, Node * currentNode){
        if (value == currentNode->value)
    }



    void insertCheck(Node* newNode, Node* &temp) {
        if (newNode->data > temp->data) {
            if (temp->right == nullptrptr) {
                temp->right = newNode;
                return;
            }
            temp = temp->right;
            insertCheck(newNode, temp);
        } 
        else if (newNode->data <= temp->data) {
            if (temp->left == nullptrptr) {
                temp->left = newNode;
                return;
            }
            temp = temp->left;
            insertCheck(newNode, temp);
        }
        else if (newNode->data == temp->data) {
            cout << "Node Tidak boleh sama!" << endl;
        }
    }

    void insertNode(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        if (root == nullptrptr) {
            root = newNode;
        } else {
            Node* temp = root;
            insertCheck(newNode, temp);
        }
    }
    */