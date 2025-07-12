#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Range {
    int start, end, idx;
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<Range> ranges(n);

    for (int i = 0; i < n; i++) {
        cin >> ranges[i].start >> ranges[i].end;
        ranges[i].idx = i;
    }

    sort(ranges.begin(), ranges.end(), [](const Range &a, const Range &b) {
        if (a.start == b.start) return a.end > b.end;
        return a.start < b.start;
    });

    vector<int> contains_some(n, 0);      
    vector<int> contained_by_some(n, 0);  

    int max_end = -1;
    for (int i = 0; i < n; i++) {
        if (ranges[i].end <= max_end) {
            contained_by_some[ranges[i].idx] = 1;
        } else {
            max_end = ranges[i].end;
        }
    }

    int min_end = 1e10;
    
    for (int i = n - 1; i >= 0; i--) {
        if (ranges[i].end >= min_end) {
            contains_some[ranges[i].idx] = 1;
        } else {
            min_end = ranges[i].end;
        }
    }

    
    for (int i = 0; i < n; i++) cout << contains_some[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++) cout << contained_by_some[i] << " ";
    cout << endl;

    return 0;
}
