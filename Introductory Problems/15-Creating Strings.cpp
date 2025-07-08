#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    string s;
    cin >> s;
    vector<string> permutations;
    
    sort(s.begin(), s.end());
    permutations.push_back(s);
    while (next_permutation(s.begin(), s.end())) {
        permutations.push_back(s);
    }
    cout << permutations.size() << endl;
    for (const auto& permutation : permutations) {
        cout << permutation << endl;
    }

    return 0;
}
