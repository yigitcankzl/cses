#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    int n;
    cin >> n;   
    vector<int> apples(n);

    for (int i = 0; i < n; i++) {
        cin >> apples[i];
    }

    int totalSum = accumulate(apples.begin(), apples.end(), 0LL);
    int minDifference = LLONG_MAX;
    // 1 << n = 2^n
    for (int i = 0; i < (1 << n); i++) {
        int sumA = 0, sumB = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sumA += apples[j];
            } else {
                sumB += apples[j];
            }
        }
        minDifference = min(minDifference, abs(sumA - sumB));
    }

    cout << minDifference << endl;

    return 0;
}
