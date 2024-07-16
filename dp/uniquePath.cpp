#include<iostream>
#include<vector>

using namespace std;

int paths(vector<vector<int>>arr,int n,int m,vector<vector<int>>&dp){

    if(n>=0 && m>=0 && arr[n][m]==-1){
        return 0;
    }
    if(n==0 && m==0){
        return 1;
    }
    if(n<0 || m<0){
        return 0;
    }

    if(dp[n][m]!=-1){
        return dp[n][m];
    }

    return dp[n][m]=paths(arr,n-1,m,dp)+paths(arr,n,m-1,dp);

}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    vector<vector<int>>dp(n,vector<int>(m,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<paths(arr,n-1,m-1,dp);
    return 0;
} 