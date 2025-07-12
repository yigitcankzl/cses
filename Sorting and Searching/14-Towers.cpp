#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    int n;
    cin >> n;

    vector<int> towers;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;

        auto it = upper_bound(towers.begin(), towers.end(), value);
        if (it == towers.end()) {
            towers.push_back(value);
        } else {
            *it = value;
        }
    }

    cout << towers.size() << endl;
    return 0;
}
