#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long power(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {  // If exp is odd
            result *= base;
        }
        base *= base;  
        exp /= 2;      
    }
    return result;
}

int isNumber(long long min, long long max, long long target, long long base) {
    int ans = max + 1;
    long long low = min;
    long long high = max;

    while (low <= high) {
        long long mid = (low + high) / 2;
        if (power(base, power(2,mid)) >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }

        int count = 0;
        bool isPresent = false;

        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i - 1]) {
                if (arr[i] == 1) {
                    isPresent = true;
                    break;
                }
                int ans = isNumber(1, arr[i - 1], arr[i - 1], arr[i]);
                arr[i] = power(arr[i], power(2,ans));
                count += ans;
            }
        }

        if (isPresent) {
            cout << -1 << endl;
        } else {
            cout << count << endl;
        }
    }
    return 0;
}
