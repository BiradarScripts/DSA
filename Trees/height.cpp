#include<iostream>

using namespace std;

class Node{
public:
    int data;
    Node*left;
    Node*right;
    Node(int a){
        data=a;
        left=NULL;
        right=NULL;
    }
};

int maxi=0;
bool isBalanced=true;

int height(Node*root){
    if(root==NULL){
        return  0;
    }
    int lh=height(root->left);
    int rh=height(root->right);

    return 1+max(lh,rh);
}

bool checkBalanced(Node*root){
    if(root==NULL){
        return true;
    }
    int lh=height(root->left);
    int rh=height(root->right);

    return (abs(lh-rh)<=1) && checkBalanced(root->left) && checkBalanced(root->right);
}

//or

int check(Node*root){
    if(root==NULL){
        return 0;
    }
    int lh=check(root->left);
    int rh=check(root->right);

    isBalanced=(abs(lh-rh)<=1) && checkBalanced(root->left) && checkBalanced(root->right);

    return 1+max(lh,rh);
}


int diameter(Node*root){
    if(root==NULL){
        return 0;
    }
    int lh=diameter(root->left);
    int rh=diameter(root->right);

    maxi=max(maxi,lh+rh);
    return 1+max(lh,rh);
}

int main(){
    Node*root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
}