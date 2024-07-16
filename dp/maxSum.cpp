#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int answer=INT_MIN;

int maxSum(vector<int>arr,int index,vector<int>&dp){
    if(index==0){
        dp[0]=arr[0];
        return arr[0];
    }else if(index==1){
        dp[1]=arr[1];
        return arr[1];
    }else if(index==2){
        dp[2]=arr[0];
        return arr[0];
    }
    
    if(dp[index]!=-1){
        return dp[index];
    }

    dp[index]=max(maxSum(arr,index-2,dp),maxSum(arr,index-3,dp));

    answer=max(answer,dp[index]+arr[index]);
    
    return max(dp[index],arr[index]);
}

int main(){
    vector<int>arr={1,2,3,4,5,6,7,7,9,10};
    vector<int>dp(arr.size(),-1);
    maxSum(arr,arr.size()-1,dp);
    cout<<answer<<endl;
    return 0;
}