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