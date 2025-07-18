#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {    
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i].first;
        values[i].second = i + 1;
    }

    sort(values.begin(), values.end());
    
    for (int i = 0; i < n - 3; i++) {
        for (int j = i + 1; j < n - 2; j++) {
            int target = x - values[i].first - values[j].first;
            int left = j + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = values[left].first + values[right].first;
                
                if (sum == target) {
                    vector<int> result = {
                        values[i].second, 
                        values[j].second, 
                        values[left].second, 
                        values[right].second
                    };
                    sort(result.begin(), result.end());
                    cout << result[0] << " " << result[1] << " " << result[2] << " " << result[3] << endl;
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
    }
    
    cout << "IMPOSSIBLE" << endl;
    
    return 0;
}