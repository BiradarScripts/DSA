#include <iostream>
#include <vector>
#include<string>

#define ll long long

using namespace std;

int sumOfDigits(int n) {
    int sum = 0;
    while(n>0) {
        sum += n%10;
        n = n/10;
    }
    return sum;
}

int main() {
    int n,m;
    cin>>n>>m;
    
}
