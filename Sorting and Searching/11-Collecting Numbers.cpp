#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> positions(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        positions[a[i]] = i;
    }

    int rounds = 1;
    for (int i = 2; i <= n; i++) {
        if (positions[i] < positions[i - 1]) {
            rounds++;
        }
    }

    cout << rounds << endl;
    return 0;
}

