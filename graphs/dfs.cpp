 #include<iostream>
 #include<vector>
 

using namespace std;

void dfs(vector<vector<int>>adj,vector<int>&vis,vector<int>&dfsResult,int node){
     vis[node]=1;
     dfsResult.push_back(node);
     for(auto it:adj[node]){
        if(!vis[it]){
            dfs(adj,vis,dfsResult,it);
        }
     }
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
    vector<int>vis(n,0);
    vector<int>dfsResult;
    dfs(adj,vis,dfsResult,0);
    for(auto it:dfsResult){
        cout<<it<<" ";
    }
    return 0;
}