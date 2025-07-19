#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, x;
    cin >> n >> x;
    vector<int> values(n);
    
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    
    map<int, int> prefix_count;
    prefix_count[0] = 1; 
    
    int prefix_sum = 0;
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        prefix_sum += values[i];
        
        count += prefix_count[prefix_sum - x];
        
        prefix_count[prefix_sum]++;
    }
    
    cout << count << endl;
    return 0;
}