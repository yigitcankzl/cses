#include "bits/stdc++.h"
using namespace std;
#define int long long

void hanoi(int n, int source, int via, int target, vector<pair<int, int>>& moves) {
    if (n == 1) {
        moves.push_back({source, target});
        return;
    }
    hanoi(n - 1, source, target, via, moves);
    moves.push_back({source, target});
    hanoi(n - 1, via, source, target, moves);

}


int32_t main() {
    int n;
    cin >> n;
    vector<pair<int, int>> moves;
    hanoi(n, 1, 2, 3, moves);
    cout << moves.size() << endl;
    for (const auto& move : moves) {
        cout << move.first << " " << move.second << endl;
    }
         
    return 0;
}
