#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    string s;
    cin >> s;
    int size = s.size();

    int maxCount = 1, currentCount = 1;
    for (int i = 1; i < size; i++) {
        if (s[i] == s[i - 1]) {
            currentCount++;
        } else {
            maxCount = max(maxCount, currentCount);
            currentCount = 1;
        }
    }
    maxCount = max(maxCount, currentCount);
    cout << maxCount << endl;
}