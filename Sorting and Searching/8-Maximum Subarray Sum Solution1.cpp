#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    int n;
    cin >> n;

    vector<int> values(n);
    vector<int> dp(n);

    for (int i = 0; i < n; i++){
        cin >> values[i];
    }

    dp[0] = values[0];

    for (int i = 1; i < n; i++){
        dp[i] = max(values[i], values[i]+dp[i-1]);
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
    
   return 0;
}