#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    int n;
    cin >> n;
    int result = 0;

    for (int i = 5; n / i >= 1; i *= 5) {
        result += n / i;
    }

    cout << result << endl;

    return 0;
}

