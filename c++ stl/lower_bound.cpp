#include<iostream>
#include<vector>

using namespace std;

int lowerBound(vector<int>Arr,int n,int x){
    int low=0,high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(Arr[mid]>=x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int main(){
    //stl
    //lower_bound(v.begin(),v.end(),num)
    //index=lower_bound(v.begin(),v.end(),num)-v.begin();
}