#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//basically using a parrot(memoization) array to store the parent node

void dijkstra(vector<vector<pair<int,int>>>adj,priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq,vector<int>&dist,vector<int>&dp,int src){
    dist[src]=0;
    pq.push({0,src});
    dp[src]=src;
    while(!pq.empty()){
        int node=pq.top().second;
        int dis=pq.top().first;
        pq.pop();

        for(auto it:adj[node]){
            int v=it.first;
            int w=it.second;
            if(dis+w<dist[v]){
                dist[v]=dis+w;
                //i just found a new shortest path
                dp[v]=node;
                pq.push({dist[v],v});
            }
        }
    }

    return ;
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
    vector<int>dp(n+1,-1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //src==1;
    dijkstra(adj,pq,dist,dp,1);
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<" ";
    }
    return 0;
}