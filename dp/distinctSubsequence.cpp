#include<iostream>
#include<vector>

using namespace std;

int distinctSubsequence(string a,string b,int index_1,int index_2,vector<vector<int>>&dp){
    if(index_1==-1 && index_2>-1){
        return 0;
    }else if(index_1>=-1 && index_2==-1){
        return 1;
    }

    if(dp[index_1][index_2]!=-1){
        return dp[index_1][index_2];
    }

    if(a[index_1]!=b[index_2]){
        dp[index_1][index_2]= distinctSubsequence(a,b,index_1-1,index_2,dp);
        return dp[index_1][index_2];
    }

    dp[index_1][index_2]=distinctSubsequence(a,b,index_1-1,index_2-1,dp)+distinctSubsequence(a,b,index_1-1,index_2,dp);

    return dp[index_1][index_2];
}

int main(){
    string a="babgbag";
    string b="bag";
    int n=a.length();
    int m=b.length();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    cout<<distinctSubsequence(a,b,n-1,m-1,dp);
}