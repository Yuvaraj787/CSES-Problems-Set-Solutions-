#include <bits/stdc++.h>
using namespace std;

void create(string cur, int n, int freq[]) {
    if (n == 0) {
        cout << cur << endl;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] == 0) continue;
        freq[i]--;
        char k = 'a' + i;
        create(cur + k, n - 1, freq);
        freq[i]++;
    }
}

int fact[9];

int main() {
    string s;
    cin >> s;
    
    int freq[26];
    memset(freq, 0, 26 * 4);
    memset(fact, 1, 9 * 4);

    int n = s.size();

    fact[0] = 1;
    fact[1] = 1;

    for (int i = 2; i <= 8; i++) {
        fact[i] = (fact[i - 1] * i); 
    }

    int tot = fact[n];
    
    for (char i : s) freq[i - 'a']++;

    
    for (int i = 0; i < 26; i++) {
        tot = tot / fact[freq[i]];
    }

    cout << tot << endl;

    string cur = "";

    create(cur, n, freq);

    return 0;
}