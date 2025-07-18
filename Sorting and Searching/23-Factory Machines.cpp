#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    int n,t;
    cin >> n >> t;

    vector<int> times(n);

    for (int i = 0; i < n; i++){
        cin >> times[i];
    }

    int left = 1, right = 1e18;

    while (left < right){
        int mid =  (left + right) / 2;
        int total = 0;
        for (int time: times){
            int products = mid / time;
            if (total > t - products) {
                total = t; 
                break;
            }
            total += products;
        }

        if (total >= t){
            right = mid;
        }else{
            left = mid+1;
        }
    }   

    cout << left << endl;
    
    return 0;   
}
