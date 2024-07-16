#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int ans=0;

bool isPossible(vector<int>arr,int num,int k){
    int count=0;
    for(int i=0;i<arr.size();i++){
        count+=arr[i]/k+1;
    }
    if(count<=num){
            return true;
    }
    return false;
}

void threshold(vector<int>arr,int min,int max,int k){
    int low=min;
    int high=max;
    while(low<=high){
        int mid=(low+high)/2;
        if(isPossible(arr,mid,k)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ;
}

int main(){
    vector<int>arr={1,2,5,9};
    int min=INT_MAX;
    int max=INT_MIN;
    for(int i=0;i<arr.size();i++){
        min=min<arr[i]?min:arr[i];
        max=max>arr[i]?max:arr[i];
    }
    threshold(arr,min,max,6);
    cout<<ans;
}