#include<iostream>
#include<vector>
#include<queue>


//ELOGV

using namespace std;

//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//this is how a minimum heap is created

7
3
1 2 3
2
3 2
3
3 1 5
4
1 1 2 3
3
4 3 2
9
16 2 4 2 256 2 4 2 8
11
10010 10009 10008 10007 10006 10005 10004 10003 10002 10001 10000

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
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //src==1;
    dijkstra(adj,pq,dist,1);
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}