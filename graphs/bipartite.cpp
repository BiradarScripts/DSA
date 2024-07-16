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

 }