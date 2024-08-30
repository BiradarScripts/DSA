include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <queue>
 
#define ll long long
 
using namespace std;
 
int main() {
    int a;
    cin >> a;
    for (int i = 0; i < a; i++) {
        string s;
        cin >> s;
        int n = s.size();
        map<char, ll> mp;
        vector<ll> dp(n + 1, LLONG_MAX);
        dp[0] = 0; // Initialize dp[0] to 0
 
        for (ll i = 0; i < n; i++) {
            // Take the character
            if (mp.find(s[i]) != mp.end()) {
                dp[i + 1] = min(dp[i + 1], dp[mp[s[i]]] + (i - mp[s[i]] - 1));
            }
 
            // Not take the character
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);
 
            mp[s[i]] = i;
        }
 
        cout << dp[n] << endl;
    }
    return 0;
}