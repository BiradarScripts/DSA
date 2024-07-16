#include<iostream>
#include<vector>

using namespace std;

int cutRod(vector<int>arr,int index,int length,vector<vector<int>>&dp){
    if(index==0){
        return length*arr[index];
    }
    if(length<=0){
        return 0;
    }

    if(dp[index][length]!=-1){
        return dp[index][length];
    }

    if(index+1>=length){
        dp[index][length]=max(arr[index]+cutRod(arr,index,length-arr[index],dp),cutRod(arr,index,length,dp));
    }else{
        cutRod(arr,index-1,length,dp);
    }

    return dp[index][length];
}

int main(){
    vector<int>arr={1,5,8,9,10,17,17,20};
    int length=8;
    vector<vector<int>>dp(arr.size(),vector<int>(length+1,-1));
    cout<<cutRod(arr,arr.size()-1,length,dp)<<endl;
    return 0;
}