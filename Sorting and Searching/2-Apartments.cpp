#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> applicants(n);
    vector<int> free_apartments(m);

    for (int i = 0; i < n; i++){
        cin >> applicants[i];
    }

    for (int i = 0; i < m; i++){
        cin >> free_apartments[i];
    }

    sort(applicants.begin(), applicants.end());
    sort(free_apartments.begin(), free_apartments.end());

    int i = 0, j = 0, result = 0;

    while (i < n && j < m){
        int a =  applicants[i];
        int b = free_apartments[j];

        if (abs(a-b) <= k){
            result++;
            i++;
            j++;

        }else if (b < (a-k)){
            j++;

        }else{
            i++;
        }

    }
    cout << result << endl;
    return 0;
}
