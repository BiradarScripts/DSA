 #include<iostream>
 #include<vector>
 #include<queue>

 using namespace std;

 bool isBipartie(int start,int v,vector<vector<int>>adj){
    queue<int>q;
    q.push(start);
    vector<int>color(v,-1);
    color[start]=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();

        for(auto it:adj[node]){
            if(color[it]==-1){
                color[it]=!color[node];
            }else if(color[it]==color[node]){
                return false;
            }
        }
    }
    return true;
 }

 int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<int>>adj(v);
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(isBipartie(0,v,adj)){
        cout<<"Graph is bipartite";
    }else{
        cout<<"Graph is not bipartite";
    }
    return 0;
 }