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

long long int inverse(long long int num){
    if (num == 1) return 1;

    long long int q = mod / num;
    long long int r = mod % num;

    long long int rem_inv = inverse(r);

    return (mod - (q * rem_inv) % mod + mod) % mod;
}

long long int nCr(int n, int r) {
    // n ! / (n - r) ! r !
    long long int res = 1;
    long long int nFact = 1;
    long long int rFact = 1;
    long long int nMinusRFact = 1;
    long long int cur = 1;

    for (int i = 1; i <= n; i++) {
        cur = (cur * i) % mod;
        
        if (i == n) nFact = cur;
        if (i == r) rFact = cur;
        if (i == (n - r)) nMinusRFact = cur;
    }

    res = (nFact * inverse(nMinusRFact)) % mod;

    res = (res * inverse(rFact)) % mod;

    return res;
}

void program() {
    int n, m;
    cin >> n >> m;
    // need to choose n - 1 place for bars from m + n - 1 places
    // (m + n - 1) C (n - 1)
    // (m + n - 1) ! / (m)! (n - 1)!
    cout << nCr(n + m - 1, n - 1);
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