#include<iostream>
#include<vector>

using namespace std;

bool isCycle(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&pathVis){
    vis[node]=1;
    pathVis[node]=1;
    for(auto it:adj[node]){
        if(vis[it]==0){
            if(isCycle(it,adj,vis,pathVis)){ 
                return true;
            }
        }else if(pathVis[it]){
            return true;
        }
    }
    pathVis[node]=0;
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
    }
    vector<int>vis(n,0);
    vector<int>pathVis(n,0);
    bool cycle=false;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(isCycle(i,adj,vis,pathVis)){
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