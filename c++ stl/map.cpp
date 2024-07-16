#include<iostream>
#include<map>

using namespace std;

//key,values
//unique keys sorted somewhat simmilar to the set;

int main(){
    map<int,int>mpp;
    map<int,pair<int,int>>m;

    mpp[1]=2;
    mpp[2]=3;
    mpp[3]=4;

    m[1]={2,3};
    m[2]={3,4};
    m[3]={4,5};

    // mpp.erase(1

    for(auto it=mpp.begin();it!=mpp.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

    auto itt=mpp.find(3);

    cout<<itt->second;


    //lower_bound and upper_bound
}