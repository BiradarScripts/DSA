#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int> prices,int n,int index,int buy,int sell,vector<vector<vector<int>>>&dp) {
    if(index==n-1){
        if(buy){
            return 0;
        }else{
            return prices[index];
        }
    }

    if(dp[index][buy][sell]!=-1){
        return dp[index][buy][sell];
    }

    if(!sell){

        dp[index][buy][sell]=max(prices[index]+maxProfit(prices,n,index+1,buy,!sell,dp),maxProfit(prices,n,index+1,buy,sell,dp));
    }else if(!buy){
        dp[index][buy][sell]=max(-prices[index]+maxProfit(prices,n,index+1,!buy,sell,dp),maxProfit(prices,n,index+1,buy,sell,dp));
    }

    return dp[index][buy][sell];
}

int main(){
    vector<int> prices={7,1,5,3,6,4};
    int n=prices.size();
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
    cout<<maxProfit(prices,n,0,1,0,dp);
}