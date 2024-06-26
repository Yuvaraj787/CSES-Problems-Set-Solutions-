#include <bits/stdc++.h>
using namespace std;

bool bfs(int s, int t, vector<vector<int>>& graph, int parent[]) {
    vector<int> vis(t+1, 0);
    queue<int> q;
    parent[s] = s;
    q.push(s);

    vis[s] = 1;

    while (!q.empty()) {
        
        int e = q.front();

        // cout << "get into " << e << endl;

        q.pop();

        // cout << "Possible options : ";

        for (int i = 0; i <= t; i++) {
            if (graph[e][i] > 0 && !vis[i]) {
                // cout << i << " ";
                if (i == t) {
                    parent[i] = e;
                    return true;
                }
                vis[i] = 1;
                parent[i] = e;
                q.push(i);
            }
        }

        cout << endl;

    }

    return false;
}


int main() {

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> graph(n + m + 2, vector<int> (n + m + 2, 0));

    for (int i = 1; i <= n; i++) {
        graph[0][i] = 1;
    }

    for (int i = n + 1; i <= n + m; i++) {
        graph[i][n+m+1] = 1;
    }

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][n + b] = 1;
    }

    int parent[n + m + 2];

    int total_pairs = 0;

    while (bfs(0, n + m + 1, graph, parent)) {
        // cout << "One path found " << endl;
        int mini_weight = 1e9;
        int v = n + m + 1;

        // for (int i = 0; i <= n +m + 1; i++) {
        //      cout << parent[i] << " ";
        // }

        // cout << endl;

        while (parent[v] != v) {
            // cout << v << " ";
            int u = parent[v];
            mini_weight = min(mini_weight, graph[u][v]);
            v = u;
        }

        v = n + m + 1;
        total_pairs += mini_weight;

        while (parent[v] != v) {
            int u = parent[v];
           graph[u][v] -= mini_weight;
           graph[v][u] += mini_weight;
            v = u;
        }
        
    }

    cout << total_pairs << endl;

    for (int j = n + 1; j <= n + m; j++) {
        for (int i = 1; i <= n; i++) {
         if (graph[j][i] > 0) {
            cout << i << " " << j - n << endl;
            break;
         }   
        }
    }


    return 0;
}