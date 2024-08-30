#include<iostream>
#include<vector>

using namespace std;

//step1
//select minimum and swap
//step2
//

//best case is o(n^2) and o(1)
//worst case is o(n^2) and o(n)

void selection_sort(vector<int>&arr,int n){
    for(int i=0;i<n-1;i++){
        int min_index=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        swap(arr[i],arr[min_index]);
    }
}


int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selection_sort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}