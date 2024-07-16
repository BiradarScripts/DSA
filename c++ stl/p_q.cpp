#include<iostream>
#include<queue>

using namespace std;

int main(){
    priority_queue<int>pq;

    pq.push(5);//5
    pq.push(2);//5,2
    pq.push(8);//8,5,2
    pq.push(1);//8,5,2,1

    cout<<pq.top();//8
    pq.pop();//5,2,1


    
    
}