#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> applicants(n);
    vector<int> apartments(m);

    for (int& i : applicants) {
        cin >> i;
    }

    for (int& i : apartments) {
        cin >> i;
    }

    sort(applicants.begin(), applicants.end());

    sort(apartments.begin(), apartments.end());

    int  i = 0;
    int j = 0;

    int count = 0;

    while ( i < n && j < m ) {
        int likes = applicants[i];
        if ((likes + k) < apartments[j]) {
            i++;
        } else if ((likes - k) > apartments[j]) {
            j++;
        } else {
            count++;
            i++;j++;
        }
    }

    cout << count;


    return 0;
}