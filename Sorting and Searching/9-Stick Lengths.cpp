#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    int n;
    cin >> n;

    vector<int> sticks(n);
    for (int i = 0; i < n; i++) {
        cin >> sticks[i];
    }

    sort(sticks.begin(), sticks.end());
    int median = sticks[n / 2]; 

    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        total_cost += abs(sticks[i] - median);
    }

    cout << total_cost << endl;
    return 0;
}
