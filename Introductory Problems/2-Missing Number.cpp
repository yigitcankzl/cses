#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int missingNumber = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] == missingNumber) {
            missingNumber++;
        }
    }
    cout << missingNumber << endl;
}