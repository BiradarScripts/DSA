#include<iostream>
#include<vector>

using namespace std;

bool isPossible(string s, int n, int m, int k,int jumps, vector<vector<vector<int>>>& dp) {

    if (n == 0) {
        return true;
    }

    if (dp[n][jumps][k] != -1) {
        return dp[n][jumps][k];
    }

    bool isCheck = false;

    if(jumps==0){
        jumps=m;
    }

    if(s[n]=='L'){
        for (int i = 1; i <= m; i++) {
            if (n - i >= 0 && s[n-i]!='C') {
                isCheck = isCheck || isPossible(s, n - i, m, k,jumps-i, dp);
            }
        }
    }

    if(s[n]=='W'){
        for (int i = 1; i <= k; i++) {
            if (n - i >= 0 && s[n-i]!='C'){
                isCheck = isCheck || isPossible(s, n - i, m, k-i,jumps,dp);
            }
        }
    }
    
    return dp[n][jumps][k] = isCheck;
}

int main() {
    int a;
    cin >> a;
    for (int t = 0; t < a; t++) {
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;

        vector<vector<vector<int>>> dp(n + 2, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));

        s='L'+s+'L';

        if (isPossible(s, n+1, m, k,m, dp)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
