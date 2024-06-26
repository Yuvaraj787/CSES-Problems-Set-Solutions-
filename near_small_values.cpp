#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int& i : arr) {
        cin >> i;
    }

    vector<int> nears(n);
    nears[0] = -1;

    int mini = arr[0];

    for (int i = 1; i < n; i++) {
        
        int j = i - 1;
        mini = min(arr[i], mini);
        
        if (mini >= arr[i]) {
            nears[i] = -1;
            continue;
        }

        while (arr[j] >= arr[i]) {
            j = nears[j];
        }

        nears[i] = j;
    }

    for (int t : nears) {
        cout << t + 1 << " ";
    }


    return 0;
}