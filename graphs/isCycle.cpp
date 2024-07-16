#include<iostream>
#include<vector>
#include<queue>

using namespace std;


bool isCycle(vector<vector<int>>&adj,vector<int>vis,int src){
    vis[src]=1;
    queue<pair<int,int>>q;
    q.push({src,-1});
    while(!q.empty()){
        pair<int,int>p=q.front();
        q.pop();
        for(auto it:adj[p.first]){
            if(vis[it]==1 && p.first!=it){
                return true;
            }
            vis[it]=1;
            q.push({it,p.first});
        }
    }
    return false;
}
 
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    vector<int>vis(n,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool cycle=false;

    //this is very important as if there are multiple components that won't traverse on all the components
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(isCycle(adj,vis,i)){
                cycle=true;
                break;
            }
        }
    }
    if(cycle){
        cout<<"Cycle is present"<<endl;
    }
    else{
        cout<<"Cycle is not present"<<endl;
    }
    return 0;
}