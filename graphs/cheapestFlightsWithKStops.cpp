#include<iostream>
#include<vector>
#include<queue>

using namespace std;
                                    //node,dist
int cheapestFlight(vector<vector<pair<int,int>>>adj,int src,int dst,int k,int n){
    queue<pair<int,pair<int,int>>>q;
    q.push({src,{0,0}});
    //steps,dit,node;
    vector<int>dist(n,1e9);
    dist[src]=0;

    while(!q.empty()){
        auto it=q.front();
        int steps=it.first;
        int cost=it.second.first;
        int node=it.second.second;
        q.pop();

        if(steps>k)continue;

        for(auto it:adj[node]){ 
            int next=it.first;
            int distance=it.second;
            if(dist[next]>distance+cost){
                dist[next]=distance+cost;
                q.push({next,{distance+cost,steps+1}});
            }
        }
    }

    return dist[dst]==1e9?-1:dist[dst];
}

int main(){
    int n=3;
    vector<vector<pair<int,int>>>adj(n);
    adj[0].push_back({1,100});
    adj[1].push_back({2,100});
    adj[0].push_back({2,500});
    cout<<cheapestFlight(adj,0,2,1,n);
    return 0;
}   