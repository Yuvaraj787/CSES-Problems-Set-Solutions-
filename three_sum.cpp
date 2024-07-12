#include <bits/stdc++.h>
using namespace std;


using tp = chrono::high_resolution_clock::time_point;

using ll = long long;
using pii = pair<int,int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;

int mod = 1e9 + 7;

void printCurrentTime() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    int hour = now->tm_hour % 12;
    hour = hour ? hour : 12; // handle midnight case
    cout << "Last Run Time reporting : ";
    cout << hour << ':'
              << (now->tm_min < 10 ? "0" : "") << now->tm_min
              << (now->tm_hour >= 12 ? " PM" : " AM") << endl << endl;
}

void printRuntime(tp start, tp end) {
    cout << endl;
    chrono::duration<double> duration = end - start;

    cout << fixed << setprecision(6);
    cout << "Runtime: " << duration.count() << " seconds" << endl;
}

void program() {

    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    map<int,queue<int>> mp;

    int idx = 1;

    for (int& i : arr) {
        cin >> i;
        mp[i].push(idx++);
    }
    
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        int rem = target - arr[i];
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = arr[j] + arr[k];
            if (sum == rem) {
                int f = mp[arr[i]].front();
                mp[arr[i]].pop();
                int s = mp[arr[j]].front();
                mp[arr[j]].pop();
                int t = mp[arr[k]].front();
                mp[arr[k]].pop();
                cout << f << " " << s << " " << t;
                return;
            } else if (sum > rem) {
                k--;
            } else {
                j++;
            }
        }
    }

    cout << "IMPOSSIBLE";

}

int main() {    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // printCurrentTime();
    auto start = chrono::high_resolution_clock::now();

    program();

    auto end = chrono::high_resolution_clock::now();
    // printRuntime(start, end);
    return 0;
}