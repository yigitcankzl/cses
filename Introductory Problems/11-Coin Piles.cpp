#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    int t, a, b;
    cin >> t;

    while(t--){
        cin >> a >> b;
        if ((2*b -a) % 3 == 0 && (2*b - a) / 3 >= 0 && (2*a - b) % 3 == 0 && (2*a - b) / 3 >= 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        
    }
    

    return 0;
}

