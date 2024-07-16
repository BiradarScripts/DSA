 #include<iostream>
 #include<vector>

 using namespace std;

 bool subsequence(vector<int>arr,int index,int target,vector<vector<bool>>&dp){
    if(target==0){
        return true;
    }
    if(index==0){
        return arr[0]==target;
    }

    if(dp[index][target]!=-1){
        return dp[index][target];
    }

    if(target<arr[index]){
        return subsequence(arr,index-1,target,dp);
    }

    dp[index][target]=subsequence(arr,index,target-arr[index],dp) || subsequence(arr,index-1,target,dp);

    return dp[index][target];
 }

 int main(){
    vector<int>arr={2,3,7,8,10};
    int target=11;
    vector<vector<bool>>dp(arr.size(),vector<bool>(target+1,-1));
    cout<<subsequence(arr,arr.size()-1,target,dp);
 } 