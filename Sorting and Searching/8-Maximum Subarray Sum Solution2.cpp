#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    int n;
    cin >> n;
    int current_sum = 0;
    int best_sum = 0;

    for (int i = 0; i < n; i++){
        int value;
        if (i == 0){
            cin >> value;
            current_sum = value;
            best_sum = value;
            continue;
        }

        cin >> value;

        current_sum = max(value, current_sum+value);
        best_sum = max(best_sum, current_sum);

    }

    cout << best_sum << endl;

   return 0;
}