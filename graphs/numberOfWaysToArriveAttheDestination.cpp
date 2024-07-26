#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int numberOfways(vector<vector<pair<int,int>>>adj,vector<int>&dist,vector<int>&ways,priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>&pq,int src,int destination){
    dist[src]=0;
    ways[src]=1;
    pq.push({0,src});

    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int cost=it.first;
        int u=it.second;

        for(auto it:adj[u]){
            int v=it.first;
            int w=it.second;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                ways[v]=ways[u];
                pq.push({dist[v],v});
            }
            else if(dist[v]==dist[u]+w){
                ways[v]+=ways[u];
            } 
        } 
    }

    return ways[destination];
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int>dist(n+1,INT_MAX);
    vector<int>ways(n+1,0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int src=1;
    int destination=n;
    cout<<numberOfways(adj,dist,ways,pq,src,destination);
    return 0;
} 