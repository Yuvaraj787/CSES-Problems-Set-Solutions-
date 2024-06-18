#include <bits/stdc++.h>
using namespace std;



int main() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        long long k = 1l * i * i;
        long long totWays = k * (k - 1) / 2;
        long long attackWays = 1l * 4 * ( i - 2) * (i - 1);
        cout << totWays - attackWays << endl;
    }

    return 0;
}