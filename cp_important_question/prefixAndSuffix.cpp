#include<iostream>
#include<vector>

using namespace std;

void prefixSum(vector<int>arr,vector<int>&prefix,int n){
    prefix[0]=arr[0];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+arr[i];
    }
}

void suffixSum(vector<int>arr,vector<int>&suffix,int n){
    suffix[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        suffix[i]=suffix[i+1]+arr[i];
    }
}

int main(){
    int n=6;
    vector<int>arr={1,2,3,4,5,6};
    vector<int>prefix(6);
    vector<int>suffix(6);
    prefixSum(arr,prefix,n);
    suffixSum(arr,suffix,n);

    for(int i=0;i<n;i++){
        cout<<prefix[i]<<" ";
    }

    cout<<endl;

    for(int i=0;i<n;i++){
        cout<<suffix[i]<<" ";
    }

}