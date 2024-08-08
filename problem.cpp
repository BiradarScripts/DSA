#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<deque>
#include<bitset>
#include<numeric>
#include<functional>
#include<iterator>
#include<utility>
#include<complex>

using namespace std;

int main(){
    int a;
    cin >> a;
    for(int t=0;t<a;t++){
        //take input as a string

        string s;
        cin >> s;
        cout<<s<<endl;
        int n;
        cin >> n;
        int size=s.size();
        vector<vector<int>>dp(size+1,vector<int>(2,0));
        for(int i=size-1;i>=0;i--){
            if(s[i]=='.'){
                dp[i][0]=1;
            }else if(s[i]=='#'){
                dp[i][1]=1;
            }

            dp[i][0]+=dp[i+1][0];
            dp[i][1]+=dp[i+1][1];
        }
        for(int i=0;i<n;i++){
            int l,r;
            cin>>l>>r;
            int dot=dp[l][0]-dp[r][0];
            int hash=dp[l][1]-dp[r][1];
            if(dot==0){
                cout<<hash-1<<endl;
            }else if(hash==0){
                cout<<dot-1<<endl;
            }else{
                cout<<dot-1+hash-1<<endl;
            }
        }
    }
}