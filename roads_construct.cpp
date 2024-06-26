#include <bits/stdc++.h>
using namespace std;

void dfs(int s, vector<int> adj[], vector<int>& vis) {
    vis[s] = 1;
    for (int n_node : adj[s]) {
        if (vis[n_node]) continue;
        dfs(n_node, adj, vis);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];

    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n + 1, 0);

    dfs(1, adj, vis);

    int nos = 0;

    vector<int> roads;

    for (int i = 2; i <= n; i++) {
        if (vis[i]) continue;
        nos++;
        roads.push_back(i);
        dfs(i, adj, vis);
    }

    cout << nos << endl;

    for (int i = 0; i < nos; i++) {
        cout << "1 " << roads[i] << endl;
    }

    return 0;
}
