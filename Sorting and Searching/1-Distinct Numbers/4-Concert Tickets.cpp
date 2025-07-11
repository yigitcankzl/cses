#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    int n, m;
    cin >> n >> m;

    multiset<int> price;
    for (int i = 0; i < n; i++){
        int p;
        cin >> p; 
        price.insert(p);
    }

    while (m--){
        int t;
        cin >> t; 
        
        auto upper = price.upper_bound(t);
        
        if (upper == price.begin()){
            cout << -1 << endl;
            continue;
        }

        --upper;
        cout << *upper << endl;
        price.erase(upper);

    }
   return 0;
}