#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    // cout << n << endl;

    int freq[26];
    memset(freq, 0, 26 * sizeof(int));

    for (char k : s) {
        freq[k - 'A']++;
    }

    int count = 0;
    int odd = -1;
    int index = 0;
    for (int i : freq) {
        // char k = 'A' + index;
        // cout << k << " -> " << i << endl;
        if (i & 1) {
            odd = index;
            count++;
            if (count > 1) {
                cout << "NO SOLUTION" << endl;
                return 0;
            } 
        }
        index++;
    }

    // char v = 'A' + odd;
    // if (odd != -1) {
    //     cout << "THe mid is " << v << endl;
    // }

    if (n & 1) {
        if (count == 0) {
            cout << "NO SOLUTION" << endl;
            return 0;
        }
    } else {
        if (count == 1) {
            cout << "NO SOLUTION" << endl;
            return 0;
        }
    }
    int point = 0;
    for (int i = 0; i < 26; i++) {
        while (freq[i] > 1) {
            s[point] = 'A' + i;
            s[n - point - 1] = 'A' + i;
            freq[i] -= 2;
            point++;
        }
    }

    if (odd != -1) {
        s[n / 2] = 'A' + odd;
    }

    cout << s;

    return 0;
}