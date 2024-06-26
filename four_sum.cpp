#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);

    map<int, queue<int>> pos;
    int s = 0;
    for (int &i : arr) {
        cin >> i;
        if (pos.find(i) != pos.end()) {
            pos[i].push(++s);
        } else {
            queue<int> q;
            q.push(++s);
            pos[i] = q;
        }
    }

    sort(arr.begin(), arr.end());

    // for (int i : arr) cout << i << " ";
    // cout << endl;

    int prev1 = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == prev1) continue;
        int rem = x - arr[i];
        // cout << "fresh" << endl;
        // cout << "trying " << arr[i] << "  remaining " << rem << endl;
        int prev2 = -1;
        for (int j = i + 1; j < n - 2; j++) {
            if (arr[j] == prev2) continue;
            // cout << "tried " << arr[j] << endl;
            rem -= arr[j];
            int n1,m;
            n1 = j + 1;
            m = n - 1;
            while (n1 < m) {
                // cout << "swingin with " << arr[n1] << " , " << arr[m] << endl;
                if (rem == (arr[n1] + arr[m])) {

                    cout << pos[arr[i]].front() << " ";
                    pos[arr[i]].pop();
                    cout << pos[arr[j]].front() << " ";
                    pos[arr[j]].pop();
                    cout << pos[arr[n1]].front() << " ";
                    pos[arr[n1]].pop();
                    cout << pos[arr[m]].front() << " ";
                    pos[arr[m]].pop();

                    return 0; 
                } else if (rem > (arr[n1] + arr[m])) {
                    n1++;
                } else {
                    m--;
                }
            }
            prev2 = arr[j];
            rem += arr[j];
        }
        prev1 = arr[i];
    }

    cout << "IMPOSSIBLE";

    return 0;
}