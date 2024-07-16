#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <utility> // for std::pair

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

vector<vector<int>> verticalTraversal(Node* root) {
    // Map to store nodes according to their horizontal distance and level
    map<int, map<int, multiset<int>>> nodes;
    
    // Queue to perform level order traversal
    // Pair structure: {Node*, {horizontal distance, level}}
    queue<pair<Node*, pair<int, int>>> todo;
    todo.push({root, {0, 0}});
    while(!todo.empty()){
        auto p=todo.front();
        todo.pop();
        Node*tempnode=p.first;
        int x=p.second.first,y=p.second.second;
        nodes[x][y].insert(tempnode->data);
        if(tempnode->left){
            todo.push({tempnode->left,{x-1,y+1}});
        }
        if(tempnode->right){
            todo.push({tempnode->right,{x+1,y+1}});
        }
    }
    vector<vector<int>>ans;
    for(auto x:nodes){
        vector<int>temp;
        for(auto y:x.second){
            for(auto z:y.second){
                temp.push_back(z);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}

int main() {
    // Creating a sample binary tree:
    //         1
    //        / \
    //       2   3
    //      / \ / \
    //     4  5 6  7
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    vector<vector<int>> result = verticalTraversal(root);
    
    // Printing the result
    for (const auto& vec : result) {
        for (int val : vec) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}
