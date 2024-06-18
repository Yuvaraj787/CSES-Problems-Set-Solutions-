#include <bits/stdc++.h>
using namespace std;

int main() {
    long long q;
    cin >> q;
    for (long long i = 0; i < q; i++) {
        long long k;
        cin >> k;
        long long startCount = 9;
        long long digit = 1;
        long long max_long_long = numeric_limits<long long>::max() / 10;

        while (k > (startCount * digit)) {
            k -= (startCount * digit);
            if (startCount > max_long_long / 10) {
                break;  // Avoid overflow by breaking out of the loop
            }
            startCount *= 10;
            digit++;
        }

        k--;  // Convert to 0-indexed

        long long div = k / digit;
        long long rem = k % digit;

        // Calculate targetNum without using pow
        long long targetNum = 1;
        for (long long j = 1; j < digit; j++) {
            targetNum *= 10;
        }
        targetNum += div;

        string num = to_string(targetNum);
        cout << num[rem] << endl;
    }
    return 0;
}
