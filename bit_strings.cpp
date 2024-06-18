#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int mod = 1e9 + 7;
    long res = 1;
    for (int i = 0; i < n; i++) {
        res = (res * 2) % mod;
    }
    cout << res;
    return 0;
}