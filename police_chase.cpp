#include <bits/stdc++.h>
using namespace std;

int n, m;

bool bfs(int s, int t, vector<vector<int>>& graph, int parent[]) {
    vector<int> vis(n + 1, 0);
    queue<int> q;
    q.push(s);
    vis[s] = 1;

    while (!q.empty()) {
        
        int e = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (graph[e][i] > 0 && !vis[i]) {
                parent[i] = e;
                if (i == t) return true;
                q.push(i);
                vis[i] = 1;
            }
        }
    }

    return false;
}

void dfs(int s, vector<int>& vis, vector<vector<int>>& graph) {
    
    vis[s] = 1;
    
    for (int i = 1; i <= n; i++) {
        if (graph[s][i] > 0 && !vis[i]) {
            dfs(i, vis, graph);
        }
    }

}

int main() {

    cin >> n >> m;

    vector<vector<int>> graph(n+1, vector<int> (n + 1, 0)); 
    vector<vector<int>> ori_graph; 

    int a, b;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        // int ta = min(a, b);
        // int tb = max(a, b);
        // if (ta == 1) {
        //     graph[1][tb] = 1;
        // } else if (tb == n) {
        //     graph[ta][n] == 1;
        // } else {
            graph[a][b] = 1;
            graph[b][a] = 1;
        // }
    }

    ori_graph = graph;

    int parent[n + 1];

    int mini_cuts = 0;

    parent[1] = 1;

    while ( bfs(1, n, graph, parent) ) {
        int v = n;
        int mini = 1e9;
        while ( parent[v] != v ) {
            int u = parent[v];
            mini = min(mini, graph[u][v]);
            v = u;
        }

        v = n;
        while ( parent[v] != v ) {
            int u = parent[v];
            graph[u][v] -= mini;
            graph[v][u] += mini;
            v = u;
        }          

        mini_cuts += mini;

    }

    cout << mini_cuts << endl;

    vector<int> vis(n + 1, 0);

    dfs(1, vis, graph);

    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1; j <= n; j++ ) {
            if ( vis[i] && !vis[j] && ori_graph[i][j] ) {
                cout << i << " " << j << endl;
            }
        }
    }
    
    return 0;
}