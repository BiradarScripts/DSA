#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        vector<int> v(n);
        map<int, int> freqMap;

        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            freqMap[v[i]]++;
        }

        bool isPossible = false;

        for (int i = 50; i >= 1; --i) {
            freqMap[i] += freqMap[i + 1];
            if (freqMap[i] % 2 == 1) {
                cout << "YES" << endl;
                isPossible = true;
                break;
            }
        }

        if (!isPossible) {
            cout << "NO" << endl;
        }
    }
    return 0;
}
