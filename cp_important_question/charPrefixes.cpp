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
    int s;
    cin >> s;
    for(int t=0;t<s;t++){
        int n,q;
        cin>>n>>q;
        string a;
        cin>>a;
        string b;
        cin>>b;
        vector<vector<int>>prefix1(n,vector<int>(26,0));
        vector<vector<int>>prefix2(n,vector<int>(26,0));

        for(int i=0;i<n;i++){
            prefix1[i][a[i]-'a']=1;
            prefix2[i][b[i]-'a']=1;
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<26;j++){
                prefix1[i][j]+=prefix1[i-1][j];
                prefix2[i][j]+=prefix2[i-1][j];
            }
        }

        for(int i=0;i<q;i++){
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            int ans=0;
            if(l>0){
                for(int i=0;i<26;i++){
                    int count1=prefix1[r][i]-prefix1[l-1][i];
                    int count2=prefix2[r][i]-prefix2[l-1][i];
                    ans+=abs(count1-count2);
                }
            }else{
                for(int i=0;i<26;i++){
                    ans+=abs(prefix1[r][i]-prefix2[r][i]);
                }
            }
            cout<<ans/2<<endl;
        }
    }
}
