#include <bits/stdc++.h>
using namespace std;


int n, m;
int mod = 1e9 + 7;

int dfs(int s, vector<int> edges[], vector<int>& vis) {
    if (s == n - 1) return 1;
    int ways = 0;

    for (int n_node : edges[s]) {
        if (vis[n_node] != -1) {
            ways = (ways + vis[n_node]) % mod;
        } else {
            ways = (ways + dfs(n_node, edges, vis)) % mod;
        }
    }

    return vis[s] = ways;
}

int main() {
    cin >> n >> m;
    vector<int> edges[n];
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a-1].push_back(b-1); 
    }

    vector<int> vis(n, -1);

    cout << dfs(0, edges, vis);

    return 0;
}