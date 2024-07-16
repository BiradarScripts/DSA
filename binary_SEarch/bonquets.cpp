#include<iostream>
#include<vector>
#include<climits>

using namespace std;

bool isPossible(int num,int m,int k,vector<int>arr){
    int count=0;
    int b=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<=num){
            count++;
        }else if(arr[i]>num){
            count=0;
        }

        if(count==m){
            b++;
            count=0;
        }
    }
    if(b>=k){
        return true;
    }else{
        return false;
    }
}

int ans=0;

void bonquets(vector<int>arr,int min,int max,int m,int k){
    int low=min;
    int high=max;

    while(low<=high){
        int mid=(low+high)/2;
        if(isPossible(mid,m,k,arr)){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ;
}

int main(){
    vector<int>arr={7,7,7,7,13,11,12,7};
    int min=INT_MAX;
    int max=INT_MIN;
    for(int i=0;i<arr.size();i++){
        min=min<arr[i]?min:arr[i];
        max=max>arr[i]?max:arr[i];
    }
    bonquets(arr,min,max,2,3);
    cout<<ans;
}