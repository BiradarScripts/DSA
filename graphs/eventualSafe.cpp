#include<iostream>
#include<vector>

using namespace std;

bool dfsCheck(int node,vector<vector<int>>adj,vector<int>&vis,vector<int>&pathVis,vector<int>&check){
    vis[node]=1;
    pathVis[node]=1;
    
    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfsCheck(it,adj,vis,pathVis,check)==true){
                return true;
            }
        }
        else if(pathVis[it]){
            return true;
        }
    }

    check[node]=1;
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
    vector<int>check(n,0);
    bool cycle=false;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfsCheck(i,adj,vis,pathVis,check);
        }
    }

    vector<int>safeNode;
    for(int i=0;i<n;i++){
        if(check[i]==1){
            safeNode.push_back(i);
        }
    }
    

    for(auto it:safeNode){
        cout<<it<<" ";
    }

    return 0;
}