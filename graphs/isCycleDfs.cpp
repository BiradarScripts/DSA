#include<iostream>
#include<vector>

using namespace std;

bool isCycle(vector<vector<int>>&adj,vector<int>&vis,vector<int>&parent,int num){
    vis[num]=1;
    for(auto it:adj[num]){
        if(!vis[it]){
            parent[it]=num;
            isCycle(adj,vis,parent,it);
        }else if(vis[it] && parent[it]!=num){
            return true;
        }
    
    }
    return false;
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
    vector<int>parent(n,-1);
    bool cycle=false;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(isCycle(adj,vis,parent,i)){
                cycle=true;
                break;
            }
        }
    }
    if(cycle){
        cout<<"Cycle is present";
    }else{
        cout<<"Cycle is not present";
    }
    return 0;
}