#include <bits/stdc++.h>
using namespace std;

int  main() {
    long long q;
    cin >> q;
    for (long long i = 0; i < q; i++) {
        long long  k;
        cin >> k;
        long long startCount = 9;
        long long digit = 1;

        while (k > (startCount * digit)) {
            k = k - (startCount * digit);
            startCount *= 10;
            digit++;
        }

        k--;

        long long div = k / digit;
        long long rem = k % digit;

        long long targetNum = 1;
        for (long long j = 1; j < digit; j++) {
            targetNum *= 10;
        }
        targetNum += div;

        long long pos = digit - 1;

        string num = to_string(targetNum);

        cout << num[rem] << endl;
    }
    return 0;
}