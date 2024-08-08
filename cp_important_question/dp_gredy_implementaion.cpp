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

int main(){
    int a;
    cin >> a;
    for(int t=0;t<a;t++){
        int n;
        cin >> n;
        vector<ll> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        ll sum=0;
        for(int i=0;i<n;i++){
            sum+=v[i];
        }
        ll local_max1=INT_MIN;
        ll global_max1=INT_MIN;
        for(int i=0;i<n-1;i++){
            local_max1=max(v[i],v[i]+local_max1);
            global_max1=max(global_max1,local_max1);
        }
        ll local_max2=INT_MIN;
        ll global_max2=INT_MIN;
        for(int i=1;i<n;i++){
            local_max2=max(v[i],v[i]+local_max2);
            global_max2=max(global_max2,local_max2);
        }

        ll global_max=max(global_max1,global_max2);


        if(sum>global_max){
            cout << "YES" << endl;
            continue;
        }
        else{
            cout << "NO" << endl;
        }

    }
}