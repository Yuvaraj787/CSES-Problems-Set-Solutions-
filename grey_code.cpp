#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> grey;
    grey.push_back("0");
    grey.push_back("1");

    for (int i = 2; i <= n; i++) {
        int size = grey.size();
        for (int j = size - 1; j >= 0; j--) {
            grey.push_back("1" + grey[j]);
            grey[j] = "0" + grey[j];
        }
    }

    for (string w : grey) {
        cout << w << endl;
    }
    return 0;
}