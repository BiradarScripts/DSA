#include<iostream>
#include<vector>
#include<queue>
#include<stack>

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

queue<int>q;
stack<int>s;

void traversal(Node*root){

    if(root->left->left==NULL && root->left->right==NULL && root->right->left==NULL && root->right->right==NULL){
        q.push(root->left->data);
        q.push(root->right->data);
        return ;
    }

    if(root->left==NULL || root->right==NULL){
        if(root->left==NULL){
            q.push(root->right->data);
            traversal(root->right);
        }else{
            s.push(root->left->data);
            traversal(root->left);
        }
    }else{
        q.push(root->data);
        traversal(root->left);
        s.push(root->right->data);
        traversal(root->right);
    }    
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