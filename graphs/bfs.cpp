#include<iostream>
#include<vector>
#include<queue>

using namespace std;

 vector<int>bfs(int v,vector<vector<int>>adj){
    vector<int>vis(v,0);
    vis[0]=1;
    queue<int>q;
    q.push(0);
    vector<int>bfs;
    while(!q.empty()){
        int node=q.front();
        q.pop();

        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
 }

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>ans=bfs(n,adj);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;