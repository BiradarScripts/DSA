#include<iostream>
#include<vector>
#include<stack>
using namespace std;


void dfs(int node,vector<vector<int>>adj,vector<int>&vis,stack<int>&st){
    vis[node]=1;

    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,st);
        }
    }
    st.push(node);
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    vector<int>vis(n,0);
    stack<int>st;

    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,adj,vis,st);
        }
    }

    vector<int>ans;

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
   
}