#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    int n;
    cin >> n;
    
    int maxVal=0;
    int sum=0;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        if (x >maxVal){
            maxVal = x;
        }

        sum +=x;
    }
    
    cout << max(sum, 2 *maxVal) <<endl;
    
    return 0;
}
