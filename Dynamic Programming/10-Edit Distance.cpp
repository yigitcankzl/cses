#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    
    int n = s1.length();
    int m = s2.length();
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;  
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;  
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min({
                    dp[i-1][j-1],
                    dp[i-1][j],
                    dp[i][j-1]
                });
            }
        }
    }
    
    cout << dp[n][m] << endl;
    
    return 0;
}
