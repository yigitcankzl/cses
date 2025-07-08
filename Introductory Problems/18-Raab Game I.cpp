#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n, a, b , equal;
        cin >> n >> a >> b;
        equal = n - (a + b);

        if((a+b) > n) {
            cout << "NO" << endl;
            continue;

        }else if ((a == 0 || b == 0) && (a + b > 0)) {
            cout << "NO" << endl;
            continue;

        }else{
            cout << "YES" << endl;

            for(int i = 1; i <= n; i++){
                cout << i << " ";
            }
            cout << endl;

            if (a>0){
                for(int i = (a+1); i <= (n-equal); i++){
                    cout << i << " ";
                }
            }
            
            for(int i = 1; i <= a; i++){
                cout << i << " ";
            }

            for(int i = (n-equal+1); i <= n; i++){
                cout << i << " ";
            }

            cout << endl;

        }

    }

    return 0;
}
