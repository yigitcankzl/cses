#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    int n, x;
    cin >> n >> x;

    vector<int> weights(n);
    for (int i = 0; i < n; i++){
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());

    int i = 0;
    int j = n-1;
    int result = 0;

    while(i <= j){
        if (weights[i]+weights[j] <= x){
            i++;
            j--;
        }else{
            j--;
        }
        result++;
    }
    cout << result << endl;
   return 0;
}