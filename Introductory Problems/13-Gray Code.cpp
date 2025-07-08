#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    int n;
    cin >> n;

    for (int i = 0; i < pow(2, n); i++) {
        int gray = i ^ (i >> 1);
        cout << bitset<64>(gray).to_string().substr(64 - n) << endl;
    }
    
    return 0;
}