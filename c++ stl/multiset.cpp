#include<iostream>
#include<set>

using namespace std;


//sorted order 
//deleting one deletes all its replicas

int main(){
    multiset<int>ms;

    ms.insert(1);//1
    ms.insert(1);//1,1
    ms.insert(2);//1,1,2

    // ms.erase(1);

    // int cnt=ms.count(1);

    // ms.insert(2);

    // auto it=ms.find(2);

    // ms.erase(2);

    // for(auto it=ms.begin();it!=ms.end();it++){
    //     cout<<*it<<endl;
    // }

    ms.insert(3);

    for(auto it=ms.begin();it!=ms.end();it++){
        cout<<*it<<endl;
    }

    auto it=ms.find(1);

    //ms.erase(x) will completely delete all the instances of x
    //ms.erase(it) will just delete the adress corresponding to that x

    ms.erase(it);

    for(auto it=ms.begin();it!=ms.end();it++){
        cout<<*it<<endl;
    }

    // ms.erase(it,it+2);
}