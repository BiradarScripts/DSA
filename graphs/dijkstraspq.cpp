#include<iostream>
#include<vector>
#include<queue>


//ELOGV

using namespace std;

//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//this is how a minimum heap is created

void dijkstra(vector<vector<pair<int,int>>>adj,priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>&pq,vector<int>&dist,int src){
    dist[src]=0;
    pq.push({0,src});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        for(auto x:adj[u]){
            int v=x.first;
            int w=x.second;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    } 
}


int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int>dist(n+1,INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //src==1;
    dijkstra(adj,pq,dist,1);
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}