#include<iostream>
#include<vector>
#include<climits>

using namespace std;

void bellmanFord(int n,vector<vector<pair<int,int>>>adj,vector<int>&dist,int src){
    dist[src]=0;
    for(int i=0;i<n-1;i++){
        int count=0;
        for(auto it:adj){
            for(auto itt:it){
                int u=count;
                int v=itt.first;
                int w=itt.second;
                if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                }
            }
            count++;
        }
    }

    int count=0;
    for(auto it:adj){
        for(auto itt:it){
            int u=count;
            int v=itt.first;
            int w=itt.second;
            if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
                cout<<"Negative cycle detected"<<endl;
                return;
            }
        }
        count++;
    }

    return ;

}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    vector<int>dist(n,INT_MAX);
    int src;
    cin>>src;
    bellmanFord(n,adj,dist,src);
    for(int i=0;i<n;i++){ 
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    return 0;
}