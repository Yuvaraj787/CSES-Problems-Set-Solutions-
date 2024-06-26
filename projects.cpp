#include <bits/stdc++.h>
using namespace std;

using vppi = vector<pair<pair<int,int>, int>> ;
using ll = long long;

int n;

int maxDay = 0;

int lowerBound(vppi& arr, int i, int j, int targ) {
    while (i < j) {
        int mid = (i + j) / 2;
        if (arr[mid].first.first >= targ) {
            j = mid;
        } else {
            i = mid + 1;
        }
    }

    if (arr[j].first.first >= targ) return j;

    return n + 1;
}



ll dp(int i, vppi & projects, vector<ll>& memo) {


    if (i >= n) return 0;

    if (memo[i] != -1) return memo[i];
    
    int cc = projects[i].first.first;

    ll take = 0;

    int k = i;
    int sd, fd, reward;

    
    while (k < n && projects[k].first.first == cc) {

        fd = projects[k].first.second;
        reward = projects[k].second;

        int nextIndex = lowerBound(projects, 0, n - 1, fd + 1);

        take = max(take, reward + dp(nextIndex, projects, memo));
        k++;
    }

    int sI = lowerBound(projects, 0, n - 1, cc + 1);

    ll not_take = dp( sI ,projects, memo);

    return memo[i] = max(take, not_take);
}

int main() {

    cin >> n;
    vppi projects;


    for (int i = 0; i < n; i++) {
     
        int a, b, c;
     
        cin >> a >> b >> c;
        projects.push_back({{a, b}, c});
    }

    vector<ll> memo(n + 1, -1);


    sort(projects.begin(), projects.end());


    cout << dp(0, projects, memo) << endl;

    
    return 0;
}