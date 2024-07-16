#include<iostream>
#include<vector>

using namespace std;

int subsetsWithSumK(vector<int>arr,int index,int target,vector<vector<int>>&dp){
    if(index==0){
        if(target==index){
            return 1;
        }else{
            return 0;
        }
    }
    if(target==arr[index]){
        return 1;
    }

    if(dp[index][target]!=-1){
        return dp[index][target];
    }

    if(target>index){
        dp[index][target]=subsetsWithSumK(arr,index-1,target-arr[index],dp)+subsetsWithSumK(arr,index-1,target,dp);
    }else{
        dp[index][target]=subsetsWithSumK(arr,index-1,target,dp);
    }

    return dp[index][target];
    
}

int main(){
    vector<int>arr={1,2,3,4,5};
    int target=10;
    vector<vector<int>>dp(arr.size(),vector<int>(target+1,-1));
    cout<<subsetsWithSumK(arr,arr.size()-1,target,dp)<<endl;
    return 0;
}