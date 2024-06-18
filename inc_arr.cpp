#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr) {
        cin >> i;
    }
    long long cost = 0;
    int prev = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < prev) {
            cost += (prev - arr[i]);
        } else {
            prev = arr[i];
        }
    }
    cout << cost;
    return 0;
}