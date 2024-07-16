#include<iostream>
#include<vector>
#include<set>

using namespace std;

void islands(vector<vector<int>>adj,vector<vector<int>>&vis,vector<int>delRow,vector<int>delCol,int sr,int sc,set<vector<pair<int,int>>>&s){
    vis[sr][sc]=1;
    vector<pair<int,int>>v;
    v.push_back({sr,sc});
    s.insert(v);
    for(int i=0;i<4;i++){
        int nrow=sr+delRow[i];
        int ncol=sc+delCol[i];
        if(nrow>=0 && nrow<adj.size() && ncol>=0 && ncol<adj[0].size() && vis[nrow][ncol]==0 && adj[nrow][ncol]==1){
            islands(adj,vis,delRow,delCol,nrow,ncol,s);
        }
    }
}

 
 int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n,vector<int>(m,0));
    vector<vector<int>>vis(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>adj[i][j];
        }
    }

    set<vector<pair<int,int>>> s;

    vector<int>delRow={-1,0,+1,0};
    vector<int>delCol={0,+1,0,-1};


    for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){ 
            if(vis[i][j]==0 && adj[i][j]==1){
                islands(adj,vis,delRow,delCol,i,j,s);
            }
        }
    }

    cout<<s.size()<<endl;


 }