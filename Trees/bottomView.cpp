#include<iostream>
#include<vector>
#include<utility>
#include<map>
#include<queue>

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



vector<int> bottomView(Node* root) {
    // This map will store the bottom view (horizontal distance -> (level, node's data))
    map<int, pair<int, int>> mp;
    
    // Queue to perform level order traversal, storing (node, (horizontal distance, level))
    queue<pair<Node*, pair<int, int>>> q;

    // Initialize the queue with the root node
    q.push({root, {0, 0}});

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        Node* temp = p.first;
        int hd = p.second.first; // horizontal distance
        int lvl = p.second.second; // level

        // Update the map if the current level is deeper or if this is the first node at this horizontal distance
        if (mp.find(hd) == mp.end() || mp[hd].first <= lvl) {
            mp[hd] = {lvl, temp->data};
        }

        // Push left and right children with updated horizontal distance and level
        if (temp->left != nullptr) {
            q.push({temp->left, {hd - 1, lvl + 1}});
        }
        if (temp->right != nullptr) {
            q.push({temp->right, {hd + 1, lvl + 1}});
        }
    }

    // Prepare the bottom view vector to return
    vector<int> ans;
    for (auto x : mp) {
        ans.push_back(x.second.second);
    }

    return ans;
}




int main(){
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);


    

    
    vector<int> ans = bottomView(root);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}