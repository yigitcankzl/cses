#include "bits/stdc++.h"
using namespace std;
#define int long long

int power(int base, int exp, int mod) {
    int result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}


int32_t main() {
    int n;
    cin >> n;
    int MOD = 1e9 + 7; 

    cout << power(2, n, MOD) << endl;

    return 0;
}

