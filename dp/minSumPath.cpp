#include<iostream>
#include<vector>

using namespace std;

int minSumPath(vector<vector<int>>arr,int n,int m,vector<vector<int>>&dp){
    if(n==0 && m==0){
        return arr[n][m];
    }
    if(n<0 || m<0){
        //remember this very important dropping INT_MAX doesnt allow the recurssion to pass by
        //i should still be more cautious
        return INT_MAX;
    }

    if(dp[n][m]!=-1){
        return dp[n][m];
    }

    dp[n][m]=min(arr[n][m]+minSumPath(arr,n-1,m,dp),arr[n][m]+minSumPath(arr,n,m-1,dp));

    return dp[n][m];
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
    cout<<minSumPath(arr,n-1,m-1,dp);
    return 0;
}
