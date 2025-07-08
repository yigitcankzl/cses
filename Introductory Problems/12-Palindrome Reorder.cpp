#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    string s;
    cin >> s;
    int size = s.size();
    map <char, int> freq;
    
    for (char c : s){
        freq[c]++;
    }

    int oddCount = 0;
    for (auto &pair : freq) {
        if (pair.second % 2 != 0) {
            oddCount++;
        }
    }

    if (oddCount > 1) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    string half = "";
    char middle = '\0';
    for (auto &pair : freq) {
        if (pair.second % 2 != 0) {
            middle = pair.first;
        }
        half += string(pair.second / 2, pair.first);
    }

    string result = half;
    if (middle != '\0') {
        result += middle;
    }
    reverse(half.begin(), half.end());
    result += half;

    cout << result << endl;
    return 0;
}