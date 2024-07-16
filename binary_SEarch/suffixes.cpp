#include<iostream>
#include<vector>
#include<map>
#include<climits>

using namespace std;

int main(){

    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        long long n,a,b;
        cin>>n>>a>>b;
        long long index=b+1-a;
        
        if(index>=1){
            if(index>n){
                index=n;
            }
            long long profit=0;
            for(long long i=1;i<=index;i++){
                profit=profit+b-i+1;
            }
            cout<<profit+a*(n-index)<<endl;
        }
        else{
            cout<<a*(n)<<endl;
        }
    }
}