#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> price(n);
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }   

    vector<int> pages(n);
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }   

    vector<pair<int, int>> books(n);
    for (int i = 0; i < n; i++) {
        books[i] = {price[i], pages[i]};
    }

    vector<int> dp(x + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= books[i].first; j--) {
            dp[j] = max(dp[j], dp[j - books[i].first] + books[i].second);
        }
    }
    cout << dp[x] << endl;  
    
    return 0;
}
