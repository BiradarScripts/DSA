#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int maxNum(vector<int>arr,int n,int num){
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        if(i!=num){
            maxi=max(maxi,arr[i]);
        }
    }
    return maxi;
}
 

int maxMerit(vector<vector<int>>arr,int n,int day,int last,vector<vector<int>>&dp){
    if(day==0){
        return maxNum(arr[day],n,last);
    }

    if(dp[day][last]!=-1){
        return dp[day][last];
    }

    int maxi=0;

    for(int i=0;i<n;i++){ 
        if(i!=last){
            maxi=max(maxi,arr[day][i]+maxMerit(arr,n,day-1,i,dp));
        }
    }

    return dp[day][last]=maxi;

}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    vector<vector<int>>dp(n,vector<int>(n,-1));
    cout<<maxMerit(arr,n,n-1,n,dp)<<endl;
    return 0;
}