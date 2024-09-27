#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

   for(int i = 0; i < t; i++) {
        int n;
        cin >> n;

        string given = "aeiou";
        string ans = "";

        if (n <= 5) {
            for (int i = 0; i < n; i++) {
                ans += given[i];
            }
        } else {
            int counts[5] = {0};  

            int check = n / 5;
            int re = n % 5;

            for (int i = 0; i < 5; i++) {
                counts[i] = check;  
            }
            for (int i = 0; i < re; i++) {
                counts[i]++;  
            }

            for (int i = 0; i < 5; i++) {
                ans += string(counts[i], given[i]);
            }
        }

        cout << ans << endl;
    }

    return 0;
}
