#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
     int n;
    cin >> n;
    
    vector<pair<pair<int, int>, int>> customers(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        customers[i] = {{a, b}, i}; 
    }
    
    sort(customers.begin(), customers.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    vector<int> room_assignments(n);
    
    int room_count = 0;
    
    for (int i = 0; i < n; i++) {
        int arrival = customers[i].first.first;
        int departure = customers[i].first.second;
        int original_index = customers[i].second;
        
        if (!pq.empty() && pq.top().first < arrival) {
            int room_num = pq.top().second;
            pq.pop();
            room_assignments[original_index] = room_num;
            pq.push({departure, room_num});
        } else {
            room_count++;
            room_assignments[original_index] = room_count;
            pq.push({departure, room_count});
        }
    }
    
    cout << room_count << endl;
    for (int i = 0; i < n; i++) {
        cout << room_assignments[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}