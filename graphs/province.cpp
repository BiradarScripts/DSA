#include<iostream>
#include<vector>

using namespace std;

 int province(vector<vector<int>>adj,vector<int>&vis){ 
    int count=0;
    for(auto it:vis){
        if(vis[it]==0){
            count++;
            vis[it]=1;
        }
        for(auto itt:adj[it]){
            vis[itt]=1;
        }
    }
    return count;
 }