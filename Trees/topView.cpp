#include<iostream>
#include<list>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int a) {
        data = a;
        left = NULL;
        right = NULL;
    }  
};

list<int>l;

void topView(Node*root,int num){
    if(root==NULL){
        return ;
    }
    if(num==0){
        l.push_back(root->data);
        topView(root->left,-1);
        topView(root->right,1);
    }
    else if(num==-1){
        l.push_back(root->data);
        topView(root->left,-1);
    }
    else if(num==1){
        l.push_front(root->data);
        topView(root->right,1);
    }

    return;
}

int main(){
    // Creating a sample binary tree:
    //         1
    //        / \
    //       2   3
    //        \
    //         4
    //          \
    //           5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->right->left=new Node(6);
    root->right->right=new Node(7);


    topView(root,0);
    //print l from back
    for(auto i=l.rbegin();i!=l.rend();i++){
        cout<<*i<<" ";
    }

}