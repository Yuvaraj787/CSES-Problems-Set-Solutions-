#include <bits/stdc++.h>
using namespace std;

int n, m;

void dfs(int s, vector<int> adj[], vector<int>& vis, stack<int>& st, bool need) {
    vis[s] = 1;
    for (int n : adj[s]) {
        if (vis[n]) continue;
        dfs(n, adj, vis, st, need);
    }

    if (need) st.push(s);
}

int main() {
    cin >> n >> m;

    vector<int> adj[n];
    vector<int> rev[n];

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    vector<int> vis(n, 0);
    stack<int> st;

    dfs(0, adj, vis, st, true);

    for (int i = 1; i < n; i++) {
        if (vis[i]) continue;
        dfs(i, adj, vis, st, true);
    }

    int t1 = st.top();
    st.pop();
    vector<int> vis2(n,0);

    dfs(t1, rev, vis2, st, false);

    while (!st.empty()) {
        int t = st.top();
        st.pop();
        if (vis2[t]) continue;
        cout << "NO" << endl;
        cout << t + 1 << " " << t1 + 1;
        return 0;
    }

    cout << "YES";

    return 0;
}