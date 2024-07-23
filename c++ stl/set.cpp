#include<iostream>
#include<set>

using namespace std;

//sorted and unique order

int main(){
    set<int>s;

    s.insert(1);
    s.insert(2);//1,2
    s.insert(2);//1,2

    auto it=s.find(3);

    s.erase(5);

    auto it1=s.find(2);
    auto it2=s.find(4);

    s.erase(it1,it2);

    auto it=s.lower_bound(2);
    auto it=s.upper_bound(2);
    //logn

    //auto it=st.begin(); it willl become an iterator
    //auto it=(*st.begin()); it will become a value
    //if we need to get the value of a pointer use *

    //set iterator
    for(auto it=s.begin();it!=s.end();it++){
        cout<<*it<<" ";
    }
}