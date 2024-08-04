#include<iostream>

using namespace std;

//xor == even ones and zeros is 0 else i

int main(){
    int a,b;
    cin>>a>>b;
    cout<<"Before swapping: "<<a<<" "<<b<<endl;
    a = a^b;
    b = a^b;
    a = a^b;
    cout<<"After swapping: "<<a<<" "<<b<<endl;
    return 0;
} 