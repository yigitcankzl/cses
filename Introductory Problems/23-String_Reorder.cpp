#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    string s;
    cin >> s;
    vector<int> freq(26);
    for (char c : s) freq[c - 'A']++;
    
    int n = static_cast<int>(s.size());
    for (int f : freq) {
        if (f > (n + 1) / 2) {
            cout << -1 << '\n';
            return 0;
        }
    }
    
    string result;
    
    for (int pos = 0; pos < n; pos++) {
        for (int i = 0; i < 26; i++) {
            char ch = 'A' + i;
            if (freq[i] > 0 && (result.empty() || result.back() != ch)) {
                result += ch;
                freq[i]--;
                break;
            }
        }
    }
    
    cout << result << endl;
    return 0;
}