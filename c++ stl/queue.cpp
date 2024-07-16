#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue<int>q;
    q.push(1);
    q.push(2);

    q.back()+=4;

    cout<<q.front();

    cout<<q.back();//1,2,9

    q.pop();//2,9

    cout<<q.front();//2
}
