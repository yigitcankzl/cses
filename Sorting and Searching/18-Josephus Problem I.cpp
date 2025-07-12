#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    deque<int> childrens;
    for (int i = 1; i <= n; i++){
        childrens.push_back(i);
    }

    vector<int> result;

    while(!childrens.empty()){
        childrens.push_back(childrens.front());
        childrens.pop_front();

        result.push_back(childrens.front());
        childrens.pop_front();
    }

    for (int x: result){
        cout << x << " ";

    }
    cout << endl;

    return 0;
}
