#include <iostream>
#include <cmath>

using namespace std;

#define ll long long

#include <iostream>
#include <cmath>

using namespace std;

#define ll long long

// Function to find the largest power of 2 less than or equal to x using bitwise operations
ll largestPowerOf2LessThanOrEqualTo(ll x) {
    if (x < 1) {
        return 0;  // Return 0 for invalid input (as there's no power of 2 less than or equal to 0)
    }
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return (x + 1) >> 1;
}

// Function to find the smallest power of 2 greater than or equal to x using bitwise operations
ll smallestPowerOf2GreaterThanOrEqualTo(ll x) {
    if (x < 1) {
        return 1;  // The smallest power of 2 greater than or equal to any non-positive number is 1
    }
    x--;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x + 1;
}

int main() {
    ll x;
    cout << "Enter a number: ";
    cin >> x;

    ll largestPower = largestPowerOf2LessThanOrEqualTo(x);
    ll smallestPower = smallestPowerOf2GreaterThanOrEqualTo(x);

    if (largestPower != 0) {
        cout << "The largest power of 2 less than or equal to " << x << " is " << largestPower << endl;
    } else {
        cout << "No power of 2 is less than or equal to " << x << endl;
    }

    cout << "The smallest power of 2 greater than or equal to " << x << " is " << smallestPower << e

int main() {
    ll x;
    cout << "Enter a number: ";
    cin >> x;

    ll largestPower = largestPowerOf2LessThanOrEqualTo(x);
    ll smallestPower = smallestPowerOf2GreaterThanOrEqualTo(x);

    if (largestPower != -1) {
        cout << "The largest power of 2 less than or equal to " << x << " is " << largestPower << endl;
    } else {
        cout << "No power of 2 is less than or equal to " << x << endl;
    }

    cout << "The smallest power of 2 greater than or equal to " << x << " is " << smallestPower << endl;

    return 0;
}
