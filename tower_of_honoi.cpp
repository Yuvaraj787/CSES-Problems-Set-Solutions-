#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> moves;


void func(int n, int a, int b, int c) {
    if (n == 1) {
        cout << a << " " << c << endl;
        return;
    }

    func(n-1, a, c, b);

    cout << a << " " << c << endl;

    func(n-1, b, a, c);
    
}


int main() {
    int n;
    cin >> n;
    int moves_c = pow(2, n) - 1;
    cout << moves_c << endl;
    func(n, 1, 2, 3);
    return 0;
}