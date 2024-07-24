#include<iostream>
#include<vector> 
#include<set>


using namespace std;


void dijkstra(vector<vector<pair<int,int>>>adj,set<pair<int, int>> st,vector<int>&dist,int src){
    dist[src]=0;
    st.insert({0,src});
    while(!st.empty()){
        auto it=st.begin(); //it is a pointer
        int node=(*st.begin()).second;
        int dis=(*st.begin()).first;
        st.erase(it);

        for(auto it:adj[node]){
            int v=it.first;
            int w=it.second;
            if(dis+w<dist[v]){
                //i just found a new shortest path
                  //so i remove the existing one
                if(dist[v]!=1e9){
                    st.erase({dist[v],v});
                }
                //i update it and then add it
                dist[v]=dis+w;
                st.insert({dist[v],v});
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
    vector<int>dist(n+1,1e9);
    set<pair<int, int>> st;
    //src==1;
    dijkstra(adj,st,dist,1);
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}