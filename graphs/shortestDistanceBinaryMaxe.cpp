#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int shortestPath(vector<vector<int>>adj,pair<int,int>source,pair<int,int>destination,queue<pair<int,pair<int,int>>>q){
    int n=adj.size();
    int m=adj[0].size();

    vector<vector<int>>dist(n,vector<int>(m,1e9));
    dist[source.first][source.second]=0;
    q.push({0,{source.first,source.second}});

    vector<int>delRow={-1,0,+1,0};
    vector<int>delCol={0,+1,0,-1};

    while(!q.empty()){
        pair<int,pair<int,int>>p=q.front();
        q.pop();
        int d=p.first;
        int sr=p.second.first;
        int sc=p.second.second;

        for(int i=0;i<4;i++){
            int nrow=sr+delRow[i];
            int ncol=sc+delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && d+1<dist[nrow][ncol]){
                dist[nrow][ncol]=d+1;
                //if(nrow==destination.first && ncol==destination.second){
                //    return d+1}
                q.push({d+1,{nrow,ncol}});
            }
        }
    }

    return dist[destination.first][destination.second];
}

int main(){

    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>adj[i][j];
        }
    }

    pair<int,int>source;
    pair<int,int>destination;
    cin>>source.first>>source.second;
    cin>>destination.first>>destination.second;

    queue<pair<int,pair<int,int>>>q;

    cout<<shortestPath(adj,source,destination,q)<<endl;
}