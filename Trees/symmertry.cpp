#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

bool isSymmetry(Node*root1,Node*root2){
    if(root1==NULL || root2==NULL){
        return true;
    }

    return (root1->data==root2->data) && isSymmetry(root1->left,root2->right) && isSymmetry(root1->right,root2->left);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    cout<<isSymmetry(root,root);
    return 0;
}