#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    //zipping
    vector<int> vals = x;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    
    for (int i = 0; i < n; i++) {
        x[i] = lower_bound(vals.begin(), vals.end(), x[i]) - vals.begin();
    }
    
    int count = 0;
    int left = 0;
    vector<int> freq(vals.size(), 0);
    int distinct = 0;
    
    for (int right = 0; right < n; right++) {
        if (freq[x[right]] == 0) {
            distinct++;
        }
        freq[x[right]]++;
        
        while (distinct > k) {
            freq[x[left]]--;
            if (freq[x[left]] == 0) {
                distinct--;
            }
            left++;
        }
        
        count += right - left + 1;
    }
    
    cout << count << '\n';
    return 0;
}