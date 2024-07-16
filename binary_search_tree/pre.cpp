#include<iostream>
#include<vector>

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

Node*preTree(Node*root,int num){
    if(root==NULL){
        return new Node(num);
    }

    if(num<root->data){
        root->left=preTree(root->left,num);
    }
    else{
        root->right=preTree(root->right,num);
    }

    return root;
}


void preorder(Node*node){
    if(node == NULL){
        return;
    }
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}

int main(){
    vector<int>arr={10,5,1,7,40,50};
    int n=arr.size();

    Node*root=NULL;

    for(int i=0;i<n;i++){
        root=preTree(root,arr[i]);
    }

    preorder(root);


    return 0;
}