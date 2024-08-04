#include<iostream>
#include<bitset>
using namespace std;

//num << k == num*2^k;
//num >> k == num/2^k;
//not
//num = ~num;
//flip and of negative take 2s complement else leave

//if there is a negative numer always convert that inyo its 2s complement snd apply the operation else wron
//negative numbers are always stored in the form of its poitive 2s complement

int main(){
    int n;
    cin>>n;
    cout<<bitset<8>(n)<<endl;
    cout<<bitset<8>(n<<1)<<endl;
    cout<<bitset<8>(n>>1)<<endl;
    return 0;
}