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

    vector<pair<int,pair<int,int>> > edges;
    vector<pair<int,int>> adj[n];
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a - 1, { b - 1, c} } );
        adj[a - 1].push_back({b - 1, c});
    }

    vector<ll> dist(n, 1e15);
    vector<int> par(n, -1);

    dist[0] = 0;
    
    int point = -1;

    for (int j = 0; j < n; j++) {
        bool change = false;
        for (int i = 0; i < m; i++) {
            int src = edges[i].first;
            int dest = edges[i].second.first;
            int cost = edges[i].second.second;
            if (dist[dest] > dist[src] + cost) {
                dist[dest] = dist[src] + cost;
                par[dest] = src;
                if (j == n - 1) {
                    point = dest;
                };
                change = true;
            }
        }

        if (j == n - 1 && change) {
            cout << "YES" << endl;
        }
    }

    if (point == -1) {
        cout << "NO"; return;
    };
    vector<int> cycle;
    for (int i = 0; i < n; i++) point = par[point];

    for (int c = point; ;c = par[c]) {
        cycle.push_back(c + 1);
        if (c == point && cycle.size() > 1) {
            break;
        }
    }

    reverse(cycle.begin(), cycle.end());

    for (int i : cycle) {
        cout << i << " ";
    }


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