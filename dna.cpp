#include <bits/stdc++.h>
using namespace std;

int main() {
    string dna_string;
    cin >> dna_string;
    int n = dna_string.size();
    char prev = dna_string[0];
    int cur = 1;
    int maxi = 1;
    for (int i = 1; i < n; i++) {
        if (dna_string[i] == prev) {
            cur++;
            maxi = max(cur, maxi);
        } else {
            prev = dna_string[i];
            cur = 1;
        }
    }
    cout << maxi;
    return 0;
}