#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n, -1));
    queue<pair<int, int>> q;
    
    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    grid[0][0] = 0;
    q.push({0,0});

    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();

        for (int i = 0; i < 8; i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && grid[next_x][next_y] == -1){
                grid[next_x][next_y] = grid[x][y] + 1;
                q.push({next_x, next_y});

            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    
    return 0;
}

