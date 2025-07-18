#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    clock_t start = clock();
    
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i].first;
        values[i].second = i + 1;
    }
    sort(values.begin(), values.end());
    
    for (int i = 0; i < n - 2; i++) {
        int target = x - values[i].first;
        int left = i + 1;
        int right = n - 1;
        while (left < right) {
            int sum = values[left].first + values[right].first;
            if (sum == target) {
                vector<int> result = {values[i].second, values[left].second, values[right].second};
                sort(result.begin(), result.end());
                cout << result[0] << " " << result[1] << " " << result[2] << endl;
                return 0;
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
    }
    
    cout << "IMPOSSIBLE" << endl;
    
    return 0;
}