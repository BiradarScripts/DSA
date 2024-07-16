#include <iostream>
#include <utility>

using namespace std;

int main(){
    pair<int,int> p = {1,3};

    // char s[]={'A','B'};

    cout<<p.first<<" "<<p.second;

    pair<int,pair<int,int>>q={1,{1,3}};
    cout<<q.first<<" "<<q.second.first<<" "<<q.second.second;

    pair<int,int>arr[]={{1,2},{3,4},{5,6}};
    cout<<arr[0].first<<" "<<arr[0].second;

} 