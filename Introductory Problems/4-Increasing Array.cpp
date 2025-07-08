#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int operations = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            operations += a[i - 1] - a[i];
            a[i] = a[i - 1];
        }
    }
    cout << operations << endl;
    return 0;
}