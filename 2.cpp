#include <iostream>
#include <vector>
#include<map>
#include <unordered_set>

using namespace std;

#define ll long long

int main() {

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    map<int,int>mp;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]]=1;
    }
    vector<int>suffix(n+1,0);
    for(int i=n-1;i>=0;i--){
        if(mp[arr[i]]){
            suffix[i]=1;
        }
        suffix[i]=suffix[i]+suffix[i+1];
        mp[arr[i]]=0;
    }
    while(m--){
        int l;
        cin>>l;
        cout<<suffix[l-1]<<endl;
    }
    
    return 0;
}
