#include<iostream>
#include<queue>
#include<map>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};


int minTime(Node*root){
    
}

map<int,int>parentMap(Node*root){
    map<int,int>parent;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node*temp = q.front();
        q.pop();
        if(temp->left){
            parent[temp->left->data] = temp->data;
            q.push(temp->left);
        }
        if(temp->right){
            parent[temp->right->data] = temp->data;
            q.push(temp->right);
        }
    }
    return parent;
}

int main(){
    //form a tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);

    //find the minimum time to reach a node from root
}