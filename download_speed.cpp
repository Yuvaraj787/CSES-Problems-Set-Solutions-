#include <bits/stdc++.h>
using namespace std;

int n, m;

using ll = long long;

bool bfs(int s, int t, vector<vector<ll>>& graph, int parent[]) {
    vector<int> vis(t + 1, 0);

    
    priority_queue<int> q;

    q.push(s);

    vis[1] = 1;

    while (!q.empty()) {
        int e = q.top();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (graph[e][i] > 0 && !vis[i]) {
                parent[i] = e;
                if (i == t) return true;
                vis[i] = 1;
                q.push(i);
            }
        }
    }


    return false;
}

int main() {
    cin >> n >> m;

    vector<vector<ll>> graph(n + 1, vector<ll> (n + 1, 0));

    int a, b, c;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;    
        graph[a][b] = graph[a][b] + c;
    }

    int parent[n + 1];

    ll speed = 0;

    parent[1] = 1;

    while ( bfs(1, n, graph, parent) ) {

        // cout << "One pAth found" << endl;

        
        int v = n;
        ll mini_weight = 1e9;
        
        while (parent[v] != v) {
            // cout << v << " ";
            int u = parent[v];
            mini_weight = min(mini_weight, graph[u][v]);
            v = u;
        }

        v = n;
        while (parent[v] != v) {
            int u = parent[v];
            graph[u][v] -= mini_weight;
            graph[v][u] += mini_weight;
            v = u;
        }

        speed += mini_weight;

    }

    cout << speed; 

    return 0;
}