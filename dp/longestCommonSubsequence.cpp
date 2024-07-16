#include<iostream>
#include<vector>
#include <string>

//comparision,replacements,edit

using namespace std;


int longestCommonSubsequence(string a,string b,int index_1,int index_2,vector<vector<int>>&dp){
    if(index_1==0 ||index_2==0){
        if(a[index_1]!=b[index_2]){
            return 0;
        }
        return 1;
    }    

    if(dp[index_1][index_2]!=-1){
        return dp[index_1][index_2];
    }

    int isEqual=INT_MIN;
    if(a[index_1]==b[index_2]){
        isEqual=1+longestCommonSubsequence(a,b,index_1-1,index_2-1,dp);
    }

    dp[index_1][index_2]=max(isEqual,max(longestCommonSubsequence(a,b,index_1-1,index_2,dp),longestCommonSubsequence(a,b,index_1,index_2-1,dp)));
}






int main(){

} 