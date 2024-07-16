#include<iostream>
#include<stack>

using namespace std;

int main(){
    stack<int>st;

    st.push(1);
    st.push(2);
    st.push(3);

    cout<<st.top()<<endl;
    cout<<st.size()<<endl;

    cout<<st.empty(); 

    //push //pop //top

    stack<int>st1,st2;

    st1.swap(st2);
}



