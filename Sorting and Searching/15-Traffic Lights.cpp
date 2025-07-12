#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x, n;
    cin >> x >> n;

    set<int> lights;
    multiset<int> segments;

    lights.insert(0), lights.insert(x);
    segments.insert(x);

    while(n--){
        int value;
        cin >> value;

        auto it = lights.upper_bound(value);
        int right = *it;
        int left = *prev(it);

        auto seg = segments.find(right - left);
        if (seg != segments.end()) segments.erase(seg);

        segments.insert(value - left);
        segments.insert(right - value);
        lights.insert(value);

        cout << *segments.rbegin() << " ";
    }
    cout << endl;
    return 0;
}
