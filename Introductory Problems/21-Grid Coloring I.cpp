#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    vector<char> characters = {'A', 'B', 'C', 'D'};
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char original = grid[i][j];
            bool found = false;
            
            for (char character : characters) {
                if (character == original) continue;
                
                bool valid = true;

                if ((j > 0 && grid[i][j-1] == character) || (i > 0 && grid[i-1][j] == character)) {
                    valid = false;
                }
                
                if (valid) {
                    grid[i][j] = character;
                    found = true;
                    break;
                }
            }
            
            if (!found) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << grid[i] << endl;
    }
    
    return 0;
}