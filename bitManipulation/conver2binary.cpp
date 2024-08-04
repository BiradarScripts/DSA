#include<iostream>
#include<bitset>
using namespace std;

//string to integer

string convert2Binary(int n){
    string s="";
    while(n>0){
        s=to_string(n%2)+s;
        n=n/2;
    }
    return s;
}

int convert2string(string s){
    int n=0;
    int j=0;
    for(int i=s.length()-1;i>=0;i--){
        n=n+(s[i]-'0')*(1<<j);
        j++;
    }
    return n;
}

int main(){
    int n;
    cin>>n;
    cout<<convert2Binary(n)<<endl;
    string s;
    cin>>s;
    cout<<convert2string(s)<<endl;
    return 0;
}