#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> arr;

void update(int idx) {
    for (int i = idx; i <= n; i += (i & (-i))) {
        arr[i]++;
    } 
}

int sum(int idx) {
    int sum = 0;
    for (int i = idx; i; i -= (i & (-i))) {
        sum += arr[i];
    } 
    return sum;
}


int main() {
    cin >> n;
    arr.resize(n + 1);
    fill(arr.begin(), arr.end(), 0);

    vector<pair<int,int>> ele;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ele.push_back({x, i + 1});
    }

    sort(ele.begin(), ele.end(), [](pair<int,int> a, pair<int,int> b) {
        return a.first > b.first;
    });

    long long moves = 0;

    for (int i = 0; i < n; i++) {
        int pos = ele[i].second;
        int prev = sum(pos);
        moves += min(prev, i - prev);
        update(pos);
    }

    cout << moves << endl;

    return 0;
}