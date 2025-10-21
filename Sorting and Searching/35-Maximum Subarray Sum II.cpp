#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, a, b;
    cin >> n >> a >> b;
    
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + x[i];
    }
    
    int max_sum = LLONG_MIN;
    deque<int> dq;
    dq.push_back(0);
    
    for (int i = 1; i <= n; i++) {
        while (!dq.empty() && prefix[dq.back()] >= prefix[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        
        while (!dq.empty() && dq.front() < i - b) {
            dq.pop_front();
        }
        
        if (i >= a) {
            max_sum = max(max_sum, prefix[i] - prefix[dq.front()]);
        }
    }
    
    cout << max_sum << endl;
    return 0;
}