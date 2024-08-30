#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<cmath>
 
using namespace std;
 
#define ll long long
 
 
int main() {
    int a;
    cin >> a;
    for (int t = 0; t < a; t++) {
        int n;
        cin >> n;
        vector<ll> arr(n);
 
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
 
        vector<ll>prefix(n+2,0);
        for(int i=n-1;i>=0;i--){
            if(prefix[i+2]>0){
                prefix[i]=max(prefix[i+2],prefix[i+2]+arr[i]);
            }else{
                prefix[i]=arr[i];
            }
        }

        
 
        ll maxel=LLONG_MIN;
        ll temp=LLONG_MIN;
        for(int i=0;i<n;i++){
            ll temp=max(prefix[i],arr[i]);
            maxel=max(maxel,temp);
        }
 
        cout << maxel << endl;
    }
 
    return 0;
}