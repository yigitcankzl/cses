#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n,0));
    
    for (int i = 0; i<n; i++){
        for (int j =0; j<n;j++){
            set<int> used;

            for (int k = 0; k < j; k++) {
                used.insert(grid[i][k]);
            }
            for (int k = 0; k < i; k++) {
                used.insert(grid[k][j]);
            }

            int val = 0;
            while (used.count(val)) {
                val++;
            }

            grid[i][j] = val;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

