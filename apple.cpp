#include <bits/stdc++.h>
using namespace std;


long long mini = INT_MAX;
int n;

void dp(int i, long long group1, long long tot, vector<int>& arr) {

    long long group2 = tot - group1;

    mini = min(abs(group2 - group1), mini);
    
    if (i == n) return;    

    dp(i + 1, group1 + arr[i], tot, arr);

    dp(i + 1, group1, tot, arr);

}




int main() {
    
    cin >> n;

    vector<int> arr(n);

    long long tot = 0;
    
    for (int &i : arr) {
        cin >> i;
        tot += i;
    }

    dp(0, 0 * 1l, tot, arr);

    cout << mini;

    return 0;
}