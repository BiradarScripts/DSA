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


int lca(Node*root,int x,int y,int* num){
    if(root==NULL){
        return -1;
    }
    
    if(root->data==x || root->data==y){
        return root->data;
    }
    else if((lca(root->left,x,y,num)== x && lca(root->right,x,y,num)==y) || (lca(root->left,x,y,num)== y && lca(root->right,x,y,num)==x)){
        *num=root->data;
        return *num;
    }
    else if((lca(root->left,x,y,num)== x || lca(root->left,x,y,num)==y)){
        return lca(root->left,x,y,num);
    }
    else if((lca(root->right,x,y,num)== x || lca(root->right,x,y,num)==y)){
        return lca(root->right,x,y,num);
    }
    else{
        return -1;
    }
    

} 

int main(){


    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left=new Node(6);
    root->left->right->right=new Node(7);
    root->right->left = new Node(8);
    root->right->right = new Node(9);

    int num = 0;
    int y=lca(root,4,7,&num);
    cout<<num<<endl;
    return 0;
}