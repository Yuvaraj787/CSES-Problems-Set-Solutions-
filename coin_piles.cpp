#include <bits/stdc++.h>
using namespace std;

// 512 mb

// 1 int = 32bits =  4byte
// 256  integers = 1KB
// 1 Mb can accomodate =  2^8 * 2^10 = 2^18 integers
// 512 Mb can accomdate = 2^9 * 2^18 = 2^27 integers
int main() {
    int t;
    int a,b;
    cin >> t;

    while (t--) {

        cin >> a >> b;

        if (2 * a < b || 2 * b < a) {
            cout << "NO" << endl;
            continue;
        }

        int y = (2 * a - b);
        
        if (y % 3 != 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }

    }
    
    return 0;
}