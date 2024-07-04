#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void dfs(int src, vector<int> adj[], vector<int>& vis) {
    vis[src] = 1;
    for (int n_node : adj[src]) {
        if (vis[n_node]) continue;
        dfs(n_node, adj, vis);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int,pair<int,int>>> edges;

    vector<int> revAdj[n + 1];

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, {b, -c}});
        revAdj[b].push_back(a);
    }

    vector<ll> dist(n+1, 1e15);

    vector<int> vis(n + 1, 0);

    dfs(n, revAdj, vis);

    dist[1] = 0;

    vector<ll> checkPoint(n + 1, 0);

    for (int i = 1; i <= 2*n + 1; i++) {

        for (int j = 0; j < m; j++) {
            
            int dest = edges[j].second.first;
            int src = edges[j].first;
            int cost = edges[j].second.second;
            
            if (dist[src] == 1e15) continue;

            dist[dest] = min(dist[dest], dist[src] +  cost);

        }

        if (i == n - 1) {
            checkPoint = dist;
        }

    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) continue;
        if (dist[i] < checkPoint[i]) {
            cout << -1;
            return 0;
        }
    }


    cout << -dist[n];
    return 0;
}
