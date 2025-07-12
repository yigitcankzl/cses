#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    int n;
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end());
    
    int reachable=1;

    for (int i = 0; i < n; i++) {
        if (coins[i] > reachable){
            break;
        }
        reachable += coins[i];
    }

    cout << reachable << endl;
    
    return 0;   
}
