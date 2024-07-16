#include<iostream>
#include<vector>

using namespace std;

bool wildDistance(string a,string b,int index_1,int index_2,vector<vector<int>>&dp){

    if(index_1<0 && index_2<0) return true;
    if(index_1<0 && index_2>=0) return false;
    if(index_1>=0 && index_2<0){
        for(int i=0;i<index_1;i++){
            if(a[index_1]!='*')return false;
        }
    }

    if(dp[index_1][index_2]!=-1){
        return dp[index_1][index_2];
    }

    if(a[index_1]==b[index_2] || a[index_1]=='?'){
        dp[index_1][index_2]=wildDistance(a,b,index_1-1,index_2-1,dp);
    }else{
        dp[index_1][index_2]=wildDistance(a,b,index_1-1,index_2,dp) || wildDistance(a,b,index_1,index_2-1,dp);
    }

} 

int main(){
       string a="a?*";
   string b="a?*";
   int n=a.length();
   int m=b.length();
   vector<vector<int>>dp(n,vector<int>(m,-1));
}