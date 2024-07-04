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
    int n, m;
    cin >> n >> m;
    map<int,int> mp;
    
    for (int i = 0; i< n; i++) {
        int e;
        cin >> e;
        mp[e]++;
    }

    for (int i = 0; i < m; i++) {
        int e;
        cin >> e;
        auto it = mp.upper_bound(e);
        if (it == mp.begin()) {
            cout << -1 << endl;
        } else {
            it--;
            int ele = it->first;
            cout << ele << endl;
            mp[ele]--;
            if (mp[ele] == 0) {
                mp.erase(ele);
            }
        }
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