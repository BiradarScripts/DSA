#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main(){
    int a;
    cin >> a;
    for(int i=0;i<a;i++){
        int n,x,y;
        cin>>n>>x>>y;
        vector<int>arr(n,0);
        
        if(x<n){
            for(int i=x;i<n;i++){
                arr[i]=-1;
            }
        }
        if(y-2>=0){
            for(int i=0;i<y-1;i++){
                arr[i]=-1;
            }
        }

        for(int t=y-1;t<x;t++){
            arr[t]=1;
        }

        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }

        cout<<endl;
        
        
    }
}