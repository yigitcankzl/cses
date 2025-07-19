#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> values(n);
    
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    
    stack<int> st; 
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && values[st.top()] >= values[i]) {
            st.pop();
        }
        
        if (st.empty()) {
            cout << 0 << " ";
        } else {
            cout << st.top() + 1 << " ";
        }
        
        st.push(i);
    }
    
    return 0;
}