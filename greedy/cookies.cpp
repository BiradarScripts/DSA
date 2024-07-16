#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int assign(vector<int>greed,vector<int>s){
    int n=greed.size();
    int m=s.size();
    sort(greed.begin(),greed.end());
    sort(s.begin(),s.end());
    int l,r=0;

    while(l<m){
        if(greed[r]<=s[l]){
            r++;
        }
        l++;
    }
    return r;
}

int main(){
    vector<int>greed={1,2,3};
    vector<int>s={1,1};
    cout<<assign(greed,s);
    return 0;
}