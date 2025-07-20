#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> dp(n + 1, LONG_LONG_MAX);
    dp[0] = 0; 

    for (int i = 1; i <= n; ++i) {
        int temp = i;
        while (temp > 0) {
            int digit = temp % 10;
            if (digit > 0) {
                dp[i] = min(dp[i], dp[i - digit] + 1);
            }
            temp /= 10;
        }
    }

    cout << dp[n] << '\n';

    return 0;
}
