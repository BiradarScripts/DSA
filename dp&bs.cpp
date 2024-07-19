#include<iostream>
#include<vector>

using namespace std;

int main(){
    int a;
    cin>>a;
    for(int t=0;t<a;t++){
        int n;
        long long x;
        cin>>n>>x;
        vector<long long>arr(n+1);
        vector<long long>prefix(n+1,0);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            prefix[i]=prefix[i-1]+arr[i];
        }
        vector<int>dp(n+3,0);
        for(int i=n;i>=1;i--){
            if(arr[i]>x){
                dp[i]=dp[i+1];
            }else{
                int l=i;
                int r=n;
                int ans=i;
                while(l<=r){
                    int mid=(l+r)/2;
                    long long cumSum=prefix[mid]-prefix[i-1];
                    if(cumSum<=x){
                        ans=mid;
                        l=mid+1;
                    }else{
                        r=mid-1;
                    }
                }
                dp[i]=(ans-i+1);
                dp[i]+=dp[ans+2];
            }
        }

        long long sum=0;
        for(int i=1;i<=n;i++){
            sum+=dp[i];
        }

        cout<<sum<<endl;
    }
}