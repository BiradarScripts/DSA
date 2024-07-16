#include<iostream>
#include<stack>


//there are 3 more problems based on it try completing it aswell

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

class BSTiterator{
private:
    stack<Node*>st;

    void pushAllLeft(Node* root){
        while(root!=NULL){
            st.push(root);
            root=root->left;
        }
    }

public:
//constructor
    BSTiterator(Node*root){
        pushAllLeft(root);
    }

    bool hasNext(Node* root){
        return !st.empty();
    }

    int next(Node*root){
        Node*temp=st.top();
        st.pop();

        if(root->right !=NULL){
            pushAllLeft(root->right);
        }

        return temp->data;
    }
};
 
int main(){
    Node*root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->left = new Node(8);
    root->right->right = new Node(12);

    BSTiterator it(root);

    while(it.hasNext(root)){
        cout<<it.next(root)<<" ";
    }
    return 0;
}