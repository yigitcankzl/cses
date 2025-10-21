#include "bits/stdc++.h"
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    if (k == 0) {
        for (int i = 1; i <= n; i++) cout << i << " ";
        cout << endl;
        return 0;
    }

    list<int> childrens;
    for (int i = 1; i <= n; i++){
        childrens.push_back(i);
    }

    vector<int> result;
    auto it = childrens.begin();

    while(!childrens.empty()){

        int step = (k-1) % (int)childrens.size();

        for (int i = 0; i < step; i++){
            ++it;
            if (it == childrens.end()){
                it = childrens.begin();
            }
        }

        result.push_back(*it);
        it = childrens.erase(it);
        if (it == childrens.end()) it = childrens.begin();

    }

    for (int x: result){
        cout << x << " ";

    }
    cout << endl;

    return 0;
}
