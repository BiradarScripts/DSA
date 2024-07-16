#include<iostream>
#include<vector>

using namespace std;

int unboundedKnapsack(vector<int>arr,vector<int>value,int index,int capacity, vector<vector<int>>&dp){
    
    if(index==0){
        return (capacity/arr[0])*value[0];
    }


    if(dp[index][capacity]!=-1){
        return dp[index][capacity];
    }

    if(capacity>=arr[index]){
        dp[index][capacity]=max(value[index]+unboundedKnapsack(arr,value,index,capacity-arr[index],dp),unboundedKnapsack(arr,value,index-1,capacity,dp));
    }else{
        dp[index][capacity]=unboundedKnapsack(arr,value,index-1,capacity,dp);
    }


    return dp[index][capacity];

}

                               
int main(){
    vector<int>arr={1,3,4,5};
    vector<int>value={1,4,5,7};
    int capacity=8;
    vector<vector<int>>dp(arr.size(),vector<int>(capacity+1,-1));
    cout<<unboundedKnapsack(arr,value,arr.size()-1,capacity,dp);
    return 0;
}