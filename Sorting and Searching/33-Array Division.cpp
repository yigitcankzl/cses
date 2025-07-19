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
    
    int left = *max_element(x.begin(), x.end());  
    int right = accumulate(x.begin(), x.end(), 0LL);  
    
    int answer = right;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        int subarrays = 1;  
        int currentSum = 0;
        bool canDivide = true;
        
        for (int i = 0; i < n; i++) {
            if (x[i] > mid) {
                canDivide = false;
                break;
            }
            
            if (currentSum + x[i] > mid) {
                subarrays++;
                currentSum = x[i];
            } else {
                currentSum += x[i];
            }
        }
        
        if (canDivide && subarrays <= k) {
            answer = mid;
            right = mid - 1;  
        } else {
            left = mid + 1;  
        }
    }
    
    cout << answer << "\n";
    
    return 0;
}