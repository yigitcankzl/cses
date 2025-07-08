#include "bits/stdc++.h"
using namespace std;
#define int long long
int minDifference = LLONG_MAX;

void solve(int index, int sumA, int sumB, const vector<int>& apples) {
    if (index == apples.size()) {
        minDifference = min(minDifference, abs(sumA - sumB));
        return;
    }

    solve(index + 1, sumA + apples[index], sumB, apples);

    solve(index + 1, sumA, sumB + apples[index], apples);
}
int32_t main() {
    int n;
    cin >> n;   
    vector<int> apples(n);

    for (int i = 0; i < n; i++) {
        cin >> apples[i];
    }

    solve(0, 0, 0, apples);
    cout << minDifference << endl;

    return 0;
}
