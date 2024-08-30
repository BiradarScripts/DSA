#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define ll long long

int main() {
    ll num;
    cin>>num;
    string s = to_string(num);

    int n = s.size();
    map<char, string> mp;

    mp['2'] = "2";
    mp['3'] = "3";
    mp['4'] = "22";
    mp['5'] = "5";
    mp['6'] = "32";
    mp['7'] = "7";
    mp['8'] = "222";
    mp['9'] = "33";

    string ans = "";
    // for (int i = 0; i < n; i++) {
    //     if (s[i] != '1' && s[i] != '0') {  
    //         ans += mp[s[i]];
    //         cout<<ans<<" "<<i<<endl;
    //     }
    // }
    // for(char c:s){
    //     cout<<c<<endl;
    //     // if (c != '1' && c != '0') {  
    //     //     ans += mp[c];
    //     // }
    // }

    for(int i=0;i<n;i++){
        cout<<s[i]<<endl;
    }

    // Sort the resulting string in descending order to form the largest possible number
    // sort(ans.begin(), ans.end(), greater<char>());

    cout << ans << endl;

    return 0;
}
