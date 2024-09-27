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

#define ll long long

bool isPallindrome(string s,int min_length_pallindrom,k){
    int n=s.size();
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-i-1]){
            return false;
        }
    }
    return true;
}

int binary_search_maxofmin(string s,int n,int k,int min,int high){
    int max=INT_MIN;
    int mid = (min+high)/2;
    while(min<=high){
        mid=(min+high)/2;
        if(isPallindrome(s,mid,k)){
            max=mid;
            min=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return max;
}


int main(){
    int a;
    cin >> a;
    for(int t=0;t<a;t++){
        int n,k;
        cin >> n >> k;
        string s;
        s.resize(n);
        cin >> s;
        map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        map<int,int>mp1;
        for(auto x:mp){
            mp1[1]+=(x.second)%2;
            mp1[2]+=(x.second)/2;
        }
    }
}