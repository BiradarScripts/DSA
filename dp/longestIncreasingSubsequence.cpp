#include<iostream>
#include<vector>

using namespace std;


//it also has a o(n) solution aswell go through it


int lis(vector<int>arr,int index,int lastNum,int n,vector<vector<int>>&dp){
    if(index==n-1){
        if(arr[index]>=lastNum){
            return arr[index];
        }
        return 0;
    }

    if(dp[index][lastNum]!=-1){
        return dp[index][lastNum];
    }

    if(arr[index]>lastNum){
        dp[index][lastNum]=max(1+lis(arr,index+1,arr[index],n,dp),lis(arr,index+1,lastNum,n,dp));
    }else{
        dp[index][lastNum]=lis(arr,index+1,lastNum,n,dp);
    }

    return dp[index][lastNum];

}

int main(){
    vector<int>arr={10,22,9,33,21,50,41,60,80};
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(101,-1));
    cout<<lis(arr,0,0,n,dp);
    return 0;
}