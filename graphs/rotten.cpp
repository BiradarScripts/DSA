#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int timeTaken(vector<vector<int>>&garden,vector<vector<int>>&vis,vector<int> delRow,vector<int> delCol){
    queue<pair<int,pair<int,int>>>q;
    int n=garden.size();
    int m=garden[0].size();
    int x,y;
    int time;
    for(int i=0;i<garden.size();i++){
        for(int j=0;j<garden[0].size();j++){
            if(garden[i][j]==2 && vis[i][j]==0){
                x=i;
                y=j;
                q.push({0,{x,y}});
                vis[x][y]=1;
            }
        }
    }
    while(!q.empty()){
        pair<int,pair<int,int>>p=q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int nrow=p.second.first+x;
            int ncol=p.second.second+y;
            time=p.first;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && garden[nrow][ncol]==1){
                vis[nrow][ncol]=1;
                q.push({p.first+1,{nrow,ncol}});
            }
        }
    }
       
    return time;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>garden(n,vector<int>(m));
    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<int>delRow={-1,0,1,0};
    vector<int>delCol={0,1,0,-1};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>garden[i][j];
        }
    }
    cout<<timeTaken(garden,vis,delRow,delCol)<<endl;
    return 0;
}