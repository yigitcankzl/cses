#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    int n, x;
    cin >> n >> x;

    vector<int> values(n);
    map<int, int> map;

    for (int i = 0; i<n; i++){
        cin >> values[i];
        int complement = x - values[i];
        if (map.count(complement)){
            cout << map[complement] + 1 << " " << i + 1 << endl;
            return 0;
        }

        map[values[i]] = i;
    }
    
    cout << "IMPOSSIBLE" << endl;
    

    
   return 0;
}