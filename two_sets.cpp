#include <bits/stdc++.h>
using namespace std;
long n;
long tot;
/*

1 - odd
2 - odd 
3 - even
4 - even
5 - odd
6 - odd
7 - even
8 - even

*/

// 1 2 3 4    5 6 7 
int main() {
    cin >> n;

    tot = 1l * (n) * (n + 1) / 2;

    if (tot % 2 != 0) {
        cout << "NO";
        return 0; 
    }
    cout << "YES" << endl;

    vector<int> g1;
    vector<int> g2;
    if (n % 2) {
        g2.push_back(n--);       
    } 

    for (int i = 1; i <= n/2; i++) {
        if (i & 1) {
            g1.push_back(i);
            g1.push_back(n - i + 1);
        }
        else { 
            g2.push_back(i);
            g2.push_back(n - i + 1);
        }
    }    
    
    cout << g1.size() << endl;

    for (int i : g1) cout << i << " ";

    cout << endl;
    
    cout << g2.size() << endl;

    for (int i : g2) cout << i << " ";

    return 0;
}