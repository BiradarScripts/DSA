#include<iostream>
#include<vector>

using namespace std;

int minEnergy(vector<int>jump,int index,vector<int>&dp){
    if(index==0){
        return 0;
    }else if(index==1){
        dp[index]=jump[1]-jump[0];
        return dp[index];
    }

    if(dp[index]!=-1){
        return dp[index];
    }
    
    dp[index]=min(jump[index]-jump[index-1]+minEnergy(jump,index-1,dp),jump[index]-jump[index-2]+minEnergy(jump,index-2,dp));

    return dp[index];
}

int main(){
    int n;
    cin>>n;
    vector<int>jump(n);
    for(int i=0;i<n;i++){
        cin>>jump[i];
    }
}