#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs(vector<vector<int>>adj,vector<int>&vis,queue<int>&q,vector<int>&indegree,vector<int>&topoSort){
    
    while(!q.empty()){
        int node=q.front();
        vis[node]=1;
        q.pop();
        topoSort.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0 && !vis[it]){
                q.push(it);
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int> q;
    for(auto it:indegree){
        if(it == 0){
            q.push(it);
        }
    }

    vector<int> vis(n, 0);
    vector<int> topoSort;
    bfs(adj, vis, q, indegree, topoSort);

    for(auto it:topoSort){
        cout << it << " ";
    }

    
    return 0;
}