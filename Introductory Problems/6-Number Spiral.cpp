#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int y, x;
        cin >> y >> x;
        int n = max(y, x);
        if (n % 2 == 0) {
            if (y == n) {
                cout << n * n - x + 1 << endl;
            } else {
                cout << (n - 1) * (n - 1) + y << endl;
            }
        } else {
            if (x == n) {
                cout << n * n - y + 1 << endl;
            } else {
                cout << (n - 1) * (n - 1) + x << endl;
            }
        }
        

    }

    return 0;
}

