#include <bits/stdc++.h>
using namespace std;

int n, m;

int mod = 1e9 + 7;

const int maxi = 1 << 20;

int memo[20][maxi];

adj[2][20];


int dfs(int s, int count) {
    if (s == 0) {
        if (count == 1) return 1;
        return 0;
    }

    if (memo[s][count] != -1) return memo[s][count];

    if (!((count >> s) & 1)) return 0;

    int mask1 = count ^ (1 << s);

    int ans = 0;

    for (int n : adj[s]) {
        ans = (ans + dfs(n,  mask1)) % mod;
    }

    return memo[s][count] = ans;
}



int main() {
    cin >> n >> m;

    memset(memo, -1, maxi * 21 * 4);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[b - 1].push_back(a - 1);
    }

    cout << dfs(n - 1,  (1 << n) - 1) << endl;

    return 0;
}