#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    
    vector<pair<int, int>> movies;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        movies.push_back({b, a});
    }
    
    sort(movies.begin(), movies.end());

    multiset<int> end_times; 
    for (int i = 0; i < k; ++i) {
        end_times.insert(0); 
    }

    int count = 0;

    for (auto [end, start] : movies) {
        auto it = end_times.upper_bound(start);
        if (it == end_times.begin()) {
            continue; 
        }
        --it; 
        end_times.erase(it); 
        end_times.insert(end);
        count++;
    }

    cout << count << endl;

    
    return 0;
}