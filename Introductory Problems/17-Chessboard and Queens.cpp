#include "bits/stdc++.h"
using namespace std;
#define int long long
char board[8][8];
int result = 0;
bool col[8], diag1[15], diag2[15];

void solve(int row) {
    if (row == 8) {
        result++;
        return;
    }

    for (int c = 0; c < 8; c++) {
        if (board[row][c] == '*') continue;          
        if (col[c] || diag1[row + c] || diag2[row - c + 7]) continue;

        col[c] = diag1[row + c] = diag2[row - c + 7] = true;
        solve(row + 1);
        col[c] = diag1[row + c] = diag2[row - c + 7] = false;
    }
}


int32_t main() {

    for (int i = 0; i < 8; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < 8; j++) {
            board[i][j] = line[j];
        }
    }

    solve(0);
    cout << result << endl;

    return 0;
}
