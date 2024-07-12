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
    vector<pair<int,int>> adj[n];
    for (int i = 0; i < m; i++) {
        int a, b, r;
        cin >> a >> b >> r;
        adj[a - 1].push_back({b - 1, r});
        adj[b - 1].push_back({a - 1, r});
    }
    vector<int> vis(n, 0);
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int>> > pq;
    pq.push({0, 0});
    ll res = 0;
    while (!pq.empty()) {

        int edgew = pq.top().first;
        int node = pq.top().second;

        pq.pop();
        if (vis[node]) continue;
        vis[node] = 1;

        res += edgew;


        vis[node] = 1;
        for (auto n : adj[node]) {
            int ele = n.first;
            int cost = n.second;
            if (vis[ele]) continue;
            pq.push({cost, ele});
        }
    }

    for (int i : vis) {
        if (i) continue;
        cout << "IMPOSSIBLE";
        return;
    }

    cout << res;
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