#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main(){
    vector<int> v;

    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int,int>>vec;

    vec.push_back({1,3});
    vec.emplace_back(1,2);

    vector<int>va(5,100);
    //{100,100,100,100,100}

    vector<int>vj(5);

    //coping

    vector<int>vb(vj);

    //iterator

    vector<int>::iterator it = v.begin();

    cout<<*it<<endl;

    it++;

    cout<<*it<<endl;


    vector<int>::iterator itt=v.end();


    for(auto it=v.begin();it!=v.end();it++){
        cout<<*it<<endl;
    }


    //deletion


    v.erase(v.begin()+1);

    v.erase(v.begin()+1,v.begin()+2);

    //insert

    vector<int>(2,100); //{100,100}

    v.insert(v.begin(),300);//{300,100,100}

    v.insert(v.begin()+1,2,10); //{300,10,10,100,100}


    vector<int>copy(5,50);
    v.insert(v.begin(),copy.begin(),copy.end());

    v.pop_back();

    v.clear();
}