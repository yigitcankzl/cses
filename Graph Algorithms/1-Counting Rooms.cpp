#include "bits/stdc++.h"
using namespace std;
#define int long long

int n, m;
vector<string> grid;
vector<vector<bool>> visited;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y) {
    visited[x][y] = true;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && 
            !visited[nx][ny] && grid[nx][ny] == '.') {
            dfs(nx, ny);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    
    grid.resize(n);
    visited.resize(n, vector<bool>(m, false));
    
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    int room_count = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                room_count++;
                dfs(i, j);
            }
        }
    }
    
    cout << room_count << endl;
    
    return 0;
}
