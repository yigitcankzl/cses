#include <bits/stdc++.h>
using namespace std;

struct Range {
    int start, end, idx;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<Range> ranges(n);
    for (int i = 0; i < n; i++) {
        cin >> ranges[i].start >> ranges[i].end;
        ranges[i].idx = i;
    }
    
    sort(ranges.begin(), ranges.end(), [](const Range &a, const Range &b) {
        if (a.start == b.start) return a.end > b.end;
        return a.start < b.start;
    });
    
    vector<int> contains_count(n, 0);
    vector<int> contained_count(n, 0);
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ranges[j].end <= ranges[i].end) {
                contains_count[ranges[i].idx]++;
                contained_count[ranges[j].idx]++;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << contains_count[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
    
    for (int i = 0; i < n; i++) {
        cout << contained_count[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}