#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int res = 0;

    int power = 1;
    int value;

    while((value = pow(5,power)) <= n) {
        res += (n / value);
        power++;
    }


    cout << res;

    return 0;
}