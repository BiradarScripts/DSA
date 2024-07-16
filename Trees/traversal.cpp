#include<iostream>
#include<vector>
#include<queue>

using namespace std;


//          1
//       2     3
//     4  5   6  7

//inorder traversal(left-root-right)
// 4 2 5 1 6 3 7

//pre-order traversal(root left right)
// 1 2 4 5 3 6 7

//post-order traversal(left right root)
// 4 5 2 6 7 3 1

//level-order traversal
// 1 2 3 4 5 6 7

//height of tree
// 3

//size of tree
// 7

//diameter of tree
// 5
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

void preorder(Node*node){
    if(node == NULL){
        return;
    }
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node*node){
    if(node == NULL){
        return;
    }
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

void postorder(Node*node){
    if(node == NULL){
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";
}

vector<vector<int>>levelorder(Node*root){
    vector<vector<int>>ans;
    if(root==NULL)return ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int sizee=q.size();
        vector<int>level;
        for(int i=0;i<sizee;i++){
            Node*tempnode=q.front();
            q.pop();
            if(tempnode->left!=NULL)q.push(tempnode->left);
            if(tempnode->right!=NULL)q.push(tempnode->right);
            level.push_back(tempnode->data);
        }
        ans.push_back(level);
    }
    return ans;
}


int main(){
    Node*root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    return 0;
}