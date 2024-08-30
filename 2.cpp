#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int main(){

    int n;
    cin>>n;

    string s;
    cin>>s;

    map<char, string> mp;

    mp['2'] = "2";
    mp['3'] = "3";
    mp['4'] = "322";
    mp['5'] = "5";
    mp['6'] = "53";
    mp['7'] = "7";
    mp['8'] = "7222";
    mp['9'] = "7332";
    string ans = "";
    for(char c:s){
        if (c != '1' && c != '0') {  
            ans += mp[c];
        }
    }

    sort(ans.begin(), ans.end(), greater<char>());

    cout<<ans<<endl;
}