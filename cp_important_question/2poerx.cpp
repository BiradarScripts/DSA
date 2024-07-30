#include <iostream>
#include <cmath>

#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    int x = n / 2;
    //2 power x
    cout << (1LL << x) << endl; 

    return 0;
}
