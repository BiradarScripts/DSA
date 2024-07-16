#include<iostream>
#include<vector>


using namespace std;

void knapsack(vector<int>arr,vector<int>value,int index,int maxSum,int capacity,vector<vector<int>>&dp,int&ans){

    if(index==0){
        if(capacity>=arr[index]){
            maxSum=maxSum+value[index];
        }else{
            ans=max(ans,maxSum);
            return ;
        }
        ans=max(ans,maxSum);
        return ;
    }

    if(capacity>=arr[index]){
        maxSum=maxSum+value[index];
    }else{
        ans=max(ans,maxSum);
        return ;
    }

    if(dp[index][capacity]!=-1){
        ans=dp[index][capacity];
        return ;
    }

    if(capacity>=arr[index]){
        knapsack(arr,value,index-1,maxSum,capacity-arr[index],dp,ans);
        knapsack(arr,value,index-1,maxSum,capacity,dp,ans);
        dp[index][capacity]=ans;
    }else{
        knapsack(arr,value,index-1,maxSum,capacity,dp,ans);
    }

}

int main(){
    vector<int>arr={1,2,3,4,5};
    vector<int>value={1,2,3,4,5};
    int capacity=10;
    vector<vector<int>>dp(arr.size(),vector<int>(capacity+1,-1));
    int ans=0;
    knapsack(arr,value,arr.size()-1,0,capacity,dp,ans);
    cout<<ans<<endl;
    return 0;
}