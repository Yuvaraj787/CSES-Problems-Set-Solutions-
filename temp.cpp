#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long sum = n * (n + 1) / 2;
    for (int i = 0; i < n - 1; i++) {
        long long ele;
        cin >> ele;
        sum -= ele;
    }
    cout << sum;
    return 0;
}