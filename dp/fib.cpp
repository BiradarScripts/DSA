#include<iostream>
#include<vector>


using namespace std;  

//recurrsive
int fib(int n,vector<int>&dp){
    if(n<=1)return n;

    if(dp[n]!=-1) return n;

    return dp[n]=fib(n-1,dp)+fib(n-2,dp);
}

//tabulation
int fib(int n){
    vector<int>dp(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
//space optimization
int fib(int n){
    if(n<=1)return n;
    int a=0,b=1,c;
    for(int i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return b;
}

int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    for(int i=0;i<=n;i++){
        cout<<dp[i]<<" ";
    }
    
    cout<<fib(n,dp)<<endl;
    
}