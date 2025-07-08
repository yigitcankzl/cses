#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    int n;
    cin >> n;

    for (int k = 1; k <= n; k++) {
        int total_ways = k * k * (k * k - 1) / 2; 
        int attacking_ways = 0;
        
        if (k >= 3) {
            attacking_ways = 4 * (k - 1) * (k - 2);
        }
        cout << total_ways - attacking_ways << endl;
    }

    return 0;
}

