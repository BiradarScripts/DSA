#include <iostream>
#include <algorithm>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int testcases;
    cin >> testcases;

    while (testcases-- > 0) {
        ll n, m, q;
        cin >> n >> m >> q;

        vector<ll> brr(m);
        for (int i = 0; i < m; i++) {
            cin >> brr[i];  // Teacher positions
        }
        
        sort(brr.begin(), brr.end());  // Sort the teacher positions

        for (int i = 0; i < q; i++) {
            ll alpha;
            cin >> alpha;  // David's position

            ll ans = 0;

            // Find the closest teachers to the left and right of David
            auto it = lower_bound(brr.begin(), brr.end(), alpha);

            // Case where alpha is exactly at a teacher's position
            if (it != brr.end() && *it == alpha) {
                ans = 0;
            } else {
                ll left_teacher = (it == brr.begin()) ? LLONG_MIN : *(it - 1);  // Teacher to the left
                ll right_teacher = (it == brr.end()) ? LLONG_MAX : *it;  // Teacher to the right

                // If David is between two teachers
                if (alpha > left_teacher && alpha < right_teacher) {
                    ans = min(alpha - left_teacher, right_teacher - alpha);  // Minimize distance to either teacher
                } 
                // If David is beyond the rightmost teacher
                else if (alpha > right_teacher) {
                    ans = n - alpha;
                } 
                // If David is before the leftmost teacher
                else if (alpha < left_teacher) {
                    ans = alpha - 1;
                }
            }

            cout << ans <<i<< endl;
        }
    }

    return 0;
}
