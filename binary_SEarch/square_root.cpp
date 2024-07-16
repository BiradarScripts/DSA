#include<iostream>

using namespace std;


int sroot(int min,int max,int num){
    int low=min;
    int high=max;
    while(low<=high){
        int mid=(low+high)/2;
        if(mid*mid==num){
            return mid;
        }
        else if(mid*mid<num){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
}

int main(){
    cout<<sroot(0,100,100)<<endl;
}