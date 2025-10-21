#include "bits/stdc++.h"
using namespace std;
#define int long long

int MOD = 1e9 + 7;
const int MAX_H = 1e6 + 5;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> dp(MAX_H);
    dp[0] = 1; 
    dp[1] = 2;

    for (int i = 2; i < MAX_H; i++) {
        dp[i] = (dp[i - 1] * 2 + dp[i - 2] * 4) % MOD;
    }

    while (n--) {
        int h;
        cin >> h;
        cout << dp[h] << '\n';
    }
            
    return 0;
}
