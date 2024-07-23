#include<iostream>
#include<vector>
#include<climits>
#include<stack>

using namespace std;

void topoSort(int node,vector<vector<pair<int,int>>>adj,vector<int>&vis,stack<int>s){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it.first]){
            topoSort(it.first,adj,vis,s);
        }
    }
    s.push(node);
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }

    vector<int>vis(n);
    stack<int>s;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            topoSort(i,adj,vis,s);
        }
    }

    vector<int>dist(n,1e9);
    
    dist[0]=0;
    while(!s.empty()){
        int node=s.top();
        s.pop();

        for(auto it:adj[node]){
            if(dist[node]+it.second<dist[it.first]){
                dist[it.first]=dist[node]+it.second;
            }
        }
    }

    for(int i=0;i<n;i++) {
        if(dist[i]==1e9){
            cout<<"INF ";
        }else{
            cout<<dist[i]<<" ";
        }
    }

}