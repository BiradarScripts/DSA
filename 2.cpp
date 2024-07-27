#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main(){
    int a;
    cin >> a;
    for(int i=0;i<a;i++){
        int n,x;
        cin>>n>>x;

        long long check=0;

        for(int u=1;u<=x;u++){
            int vmax=min(x-u,n/u);
            for(int v=1;v<=vmax;v++){
                int wmax=min(x-u-v,(n-u*v)/(u+v));
                check+=max(0,wmax);
            }
        }

        cout<<check<<endl;
    }
}