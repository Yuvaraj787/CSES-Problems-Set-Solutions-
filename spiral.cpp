#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x,y;  
        cin >> x >> y;
        long long maxi = max(x,y);
        long long prev = (maxi - 1) * (maxi - 1);
        if (maxi & 1) {
            prev += y;
            if (x <= y) {
                prev += (y - x);
            }
        } else {
            prev += x;
            if (y <= x) {
                prev += (x - y);
            }
        }
        cout << prev << endl;
    }
    return 0;
}