#include<iostream>
#include<vector>

using namespace std;

int upperBound(vector<int>Arr,int n,int x){

    int low=0,high=n-1;
    int ans=n;
    while(low>=high){
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
    //upper_bound(v.begin(),v.end(),num)
    //index=upper_bound(v.begin(),v.end(),num)-v.begin();
}

//rotated sorted array(with and without duplicates)