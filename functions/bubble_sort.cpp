#include<iostream>
#include<vector>

using namespace std;
//best time complexity is o(n)
void bubble_sort(vector<int>&arr,int n){
    for(int i=n-1;i>=0;i++){
        int didSwap=0;
        for(int j=0;j<=i;j++){
            if(arr[j]>arr[j+1]){
                didSwap=1;
                swap(arr[j],arr[j+1]);
            }
        }
        if(didSwap==0){
            break;
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bubble_sort(arr,n);
    for(auto it:arr){
        cout<<it<<" ";
    }
}