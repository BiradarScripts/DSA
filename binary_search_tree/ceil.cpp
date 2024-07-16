#include<iostream>


using namespace std;

class Node{
public:
    int data;
    Node*left;
    Node*right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

int ans=-1;

void ceil(Node*root,int num){

    if(root==NULL){
        return ;
    }
    if(root->data>num){
        ans=root->data;
        ceil(root->left,num);
    }else{
        ceil(root->right,num);
    }

    return;
}

bool isBst(Node*root){
    if(root==NULL){
        return true;
    }

    if(root->left && root->right){
        return (root->data > root->left->data) && (root->right->data > root->data) && isBst(root->right) && isBst(root->left);
    }
    if((!root->right) && root->left){
        return root->data > root->left->data && isBst(root->left);
    }
    if((!root->left) && root->right){
        return root->data < root->right->data && isBst(root->right);
    }

    return true;
}

int main(){
    Node*root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(18);
    int num = 6;
    // ceil(root,num);
    // cout<<ans<<endl;
    cout<<isBst(root);
    return 0;
}