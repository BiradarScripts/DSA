#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
#include<cmath>

using namespace std;

void bits(vector<int>&b,int num){
    if(num==1){
        b.push_back(1);
        return;
    }
    b.push_back(num%2);
    bits(b,num/2);
}

int main(){
    // int n;
    // cin>>n;
    // vector<int> v;
    // bits(v,n);
    // for (auto it = v.rbegin(); it != v.rend(); ++it) {
    //     cout << *it;
    // }
    cout<<pow(2,33);
}