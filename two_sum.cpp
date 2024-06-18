#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,x;
    cin >> n >> x;

    map<int,int> mp;

    for (int i = 1; i <= n; i++) {
        int ele;
        cin >> ele;
        if (mp.find(x - ele) != mp.end()) {
            cout << mp[x-ele] << " " << i;
            return 0;
        }
        mp[ele] = i;
    }

    cout << "IMPOSSIBLE";

    return 0;
}