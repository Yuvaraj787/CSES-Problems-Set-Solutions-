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
const int si = 1e6 + 1;
ll hash1[si][3];


ll dp(int n, int w) {
    if (n == 1) return 1;
    if (hash1[n][w] != -1) return hash1[n][w];
    if (w == 1) {
        return hash1[n][w] = ((4 * dp(n - 1, 1)) +  dp(n - 1, 2)) % mod;
    } else {
        return hash1[n][w] = ((2 * dp(n - 1, 2)) + dp(n - 1, 1)) % mod;
    }
}

void program() {
    memset(hash1, -1, si * 3 * sizeof(ll));
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (dp(n, 1) + dp(n, 2)) % mod << endl;
    }
}

int main() {    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    printCurrentTime();
    auto start = chrono::high_resolution_clock::now();

    program();

    auto end = chrono::high_resolution_clock::now();
    printRuntime(start, end);
    return 0;
}