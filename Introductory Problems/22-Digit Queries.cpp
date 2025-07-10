#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    int q,k;
    cin >> q;

    while(q--){
        cin >> k;
        
        int start = 1, length = 1, count = 9;

        while (k > length * count) {
            k -= length * count;
            length++;
            count *= 10;
            start *= 10;
        }

        int number = start + (k - 1) / length;

        int digit_index = (k - 1) % length;

        string s = to_string(number);

        cout << s[digit_index] << endl;
    }

    

    return 0;
}

