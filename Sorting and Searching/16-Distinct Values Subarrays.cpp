#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> x(n);
    
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    int count = 0;
    int left = 0;
    unordered_set<int> seen;
    
    for (int right = 0; right < n; right++) {
        while (seen.count(x[right])) {
            seen.erase(x[left]);
            left++;
        }
        
        seen.insert(x[right]);
        
        count += right - left + 1;
    }
    
    cout << count << endl;
    return 0;
}