#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    int n;
    cin >> n;

    vector<pair<int,int>> movies;

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        movies.push_back({end, start}); 
    }

    sort(movies.begin(), movies.end());

    int count = 0;
    int last_end_time = 0;

    for (auto [end, start] : movies) {
        if (start >= last_end_time) {
            count++;
            last_end_time = end;
        }
    }

    cout << count << endl;
    
   return 0;
}