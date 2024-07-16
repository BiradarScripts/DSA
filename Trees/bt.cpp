#include<iostream>

using namespace std;

class Node{
public:
    int data;
    Node*left;
    Node*right;
    Node(int a){
        data = a;
        left = NULL;
        right = NULL;
    }
};

int main(){
    Node*root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    return 0;
}