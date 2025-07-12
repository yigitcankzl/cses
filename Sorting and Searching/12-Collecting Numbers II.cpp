#include "bits/stdc++.h"
using namespace std;
#define int long long

void add_affected_pairs(set<pair<int, int>>& s, int val, int n) {
    if (val > 1)
        s.insert({val - 1, val});
    if (val < n)
        s.insert({val, val + 1});
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<int> numbers(n);
    vector<int> positions(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        positions[numbers[i]] = i;
    }

    int rounds = 1;
    for (int i = 2; i <= n; i++) {
        if (positions[i] < positions[i - 1]) {
            rounds++;
        }
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        --a; --b;

        if (a == b) {
            cout << rounds << endl;
            continue;
        }

        set<pair<int, int>> affected;

        add_affected_pairs(affected, numbers[a], n);
        add_affected_pairs(affected, numbers[b], n);

        for (auto [u, v] : affected) {
            if (positions[u] > positions[v]) rounds--;
        }

        swap(numbers[a], numbers[b]);
        positions[numbers[a]] = a;
        positions[numbers[b]] = b;

        for (auto [u, v] : affected) {
            if (positions[u] > positions[v]) rounds++;
        }

        cout << rounds << endl;
    }

    return 0;
}
