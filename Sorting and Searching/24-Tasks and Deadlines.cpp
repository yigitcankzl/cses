#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> tasks(n);
    
    for (int i = 0; i < n; i++){
        int a, d;
        cin >> a >> d;
        tasks[i] = {a, d};  
    }
    
    
    sort(tasks.begin(), tasks.end());
    
    int time = 0;
    int reward = 0;
    
    for (auto task : tasks) {
        time += task.first;
        reward += task.second - time;
    }
    
    cout << reward << endl;
    
    return 0;
}
