#include<iostream>

using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int a){
        data=a;
        left=NULL;
        right=NULL;
    }
};

int maxi=0;

int maxSum(Node*root){
    if(root==NULL){
        return 0;
    }

    int lh=maxSum(root->left);
    int rh=maxSum(root->right);
    
    maxi=max(maxi,root->data+lh+rh);
     
    return max(lh,rh)+root->data;
} 

int main(){
    Node* root=new Node(10);
    root->left=new Node(2);
    root->right=new Node(10);
    root->left->left=new Node(20);
    root->left->right=new Node(1);
    root->right->right=new Node(-25);
    root->right->right->left=new Node(3);
    root->right->right->right=new Node(4);
    // cout<<maxSum(root);
    return 0;
}