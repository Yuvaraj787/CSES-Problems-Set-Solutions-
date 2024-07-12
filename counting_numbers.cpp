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

ll dp(int i, string& num, char prev, int tight, ll hash[2][2][10][19], int started) {
    if (i == num.size()) return 1;
    if (prev != '-' && hash[started][tight][prev - '0'][i] != -1) return hash[started][tight][prev - '0'][i];
    ll possi = 0;
    char last = tight ? num[i] : '9';
    for (char j = '0'; j <= last; j++)  {
        if (j == prev && started) continue;
        possi += dp(i + 1, num, j, (tight && j == last), hash, started ? 1 : j != '0');
    }
    if (prev == '-') return possi;
    return hash[started][tight][prev - '0'][i] = possi;
}

void program() {
    ll l, r;
    cin >> l >> r;
    ll hash[2][2][10][19];
    memset(hash, -1,2 * 2 * 10 * 19 * sizeof(ll));
    string num1 = to_string(l - 1);
    string num2 = to_string(r);
    ll high = dp(0, num2, '-', 1, hash, 0);
    memset(hash, -1,2 * 2 * 10 * 19 * sizeof(ll));
    ll low = dp(0, num1, '-', 1, hash, 0);
    cout << high - low;
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