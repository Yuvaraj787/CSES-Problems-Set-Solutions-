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

int dp(int i, int j, int n, vector<string>& grid, vector<vector<int>>& hash) {
    if (i > n || j > n) return 0;
    if (grid[i][j] == '*') return 0;
    if (i == n && j == n) return 1;
    if (hash[i][j] != -1) return hash[i][j];

    int right = dp(i, j + 1, n, grid, hash);
    int down = dp(i + 1, j, n, grid, hash);
    return hash[i][j] = (right + down) % mod;
}

void program() {
    int n;
    cin >> n;
    vector<string> grid(n);
    vector<vector<int>> hash(n, vector<int> (n, -1));
    for (auto& s: grid) {
        cin >> s;
    }
    cout << dp(0, 0, n - 1, grid, hash) << endl;
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