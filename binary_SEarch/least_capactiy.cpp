#include<iostream>
#include<vector>
#include<climits>

using namespace std;

bool isPossible(vector<int>arr,int num,int days){
    int sum=0;
    int count=0;
    cout<<num<<endl;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum>num){
            count++;
            sum=arr[i];
            if(i==arr.size()-1){
                if(sum!=num){
                    count++;
                }
            }
        }
    }
    // cout<<count<<endl;
    if(count>days){
        return true;
    }else{
        return false;
    }
}

int ans=0;

void shipment(vector<int>arr,int days,int min,int max){
    int low=min;
    int high=max;
    while(low<=high){
        int mid=(low+high)/2;
        if(isPossible(arr,mid,days)){
            ans=mid;
            cout<<ans<<endl;
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return ;
}

int main(){
    vector<int>arr={1,2,3,4,5,6,7,8,9,10};
    int min=INT_MAX;
    for(int i=0;i<arr.size();i++){
        min=min<arr[i]?min:arr[i];
    }
    int max=0;
    for(int i=0;i<arr.size();i++){
        max=max+arr[i];
    }
    shipment(arr,5,min,max);
    cout<<ans;
}